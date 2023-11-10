/* main.c */
#include <stdio.h>
#include "para_allocator.h"

/*
 * 问题1: 为什么在main函数中不能直接调用free(p)释放内存，而要调用free_unit(p)?
 * 答:  因为`p`指向的是一个`unit_t`结构体，这个结构体有两个字段：`number`和`msg`。
 *      `number`是一个整数，`msg`是一个指向字符串的指针。当你调用`alloc_unit(&p)`时，
 *      你为`p`分配了一个`unit_t`结构体的内存，同时也为`p->msg`分配了一个字符串的内存。
 *      所以，当你要释放`p`时，你不仅要释放`p`指向的结构体的内存，还要释放`p->msg`指向的字符串的内存。
 *      如果你只用`free(p)`，你只会释放结构体的内存，而不会释放字符串的内存。这样就会造成内存泄漏，
 *      也就是说，你分配的内存没有被正确地回收，占用了系统的资源。为了避免这个问题，
 *      你需要用`free_unit(p)`，这个函数会先释放`p->msg`指向的字符串的内存，
 *      然后再释放`p`指向的结构体的内存。这样就可以完全释放`p`所占用的内存，避免内存泄漏。
 *
 * 问题2: 为什么不能用一层指针的函数接口void alloc_unit(unit_t *p), 而一定要用两层指针的函数接口？
 * 答:  因为如果你用一层指针的函数接口，你只能修改`p`的值，而不能修改`p`指向的地址。
 *      也就是说，你只能改变`p`所存储的内容，而不能改变`p`所指向的位置。
 *      当你调用`alloc_unit(&p)`时，你的目的是让`p`指向一个新分配的`unit_t`结构体的内存。
 *      如果你用一层指针的函数接口，你只能把这个新分配的内存的地址赋给`p`的副本，而不会影响`p`本身。
 *      这样，当你回到`main`函数时，你会发现`p`还是`NULL`，没有指向任何有效的内存。
 *      为了解决这个问题，你需要用两层指针的函数接口，这样你就可以修改`p`的地址，而不是`p`的值。
 *      也就是说，你可以把这个新分配的内存的地址赋给`p`所指向的位置，而不是`p`所存储的内容。
 *      这样，当你回到`main`函数时，你会发现`p`已经指向了一个有效的内存，而不是`NULL`。
 */

int main(void)
{ 
    unit_t *p = NULL; 
    /*
        其实重点就在这里, 我们希望用一个指向unit_t结构体的指针来显示出msg和number
        一种想法是，先新建一个结构体，然后把这个结构体的地址给p
        另一中就是现在这种方法，直接改变p指针的地址,使其直接指向新结构体的地址，而这句话"p指针的地址"，就是 指针的指针,
        我们当然可以在main函数里使用第一种方法，但是我们现在是调用函数的方式，
        向函数里面传一个一级指针当参数，并不能直接改变这个指针的值，只是改变了指针的副本的值
        
        现在我想要改变这个指针所指向的地址，即这个指针的地址，即参数应该为指针的指针。
        这个想要改变变量是一个意思，要改变函数外的变量，需要传变量的地址
        现在这个变量是指针，传的就是指针的地址。
    */ 

    alloc_unit(&p); 
    printf("number: %d\nmsg: %s\n", p->number, p->msg); 
    free_unit(p); 
    p = NULL; 
    return 0;
}
