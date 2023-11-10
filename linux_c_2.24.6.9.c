#include <stdio.h>
#include <stdarg.h>

void myprintf(const char *format, ...)
{ 
    va_list ap; 
    char c; 
    va_start(ap, format); 
    
    // careful to the warning: suggest parentheses around assignment used as truth value
    while ((c = *format++)) { 
        switch(c) {
            case 'c': { 
                /* char is promoted to int when passed through '...' */ 
                char ch = va_arg(ap, int); 
                putchar(ch); 
                break; 
            } 
            case 's': { 
                char *p = va_arg(ap, char *); 
                fputs(p, stdout); 
                break; 
            } 
            default: 
                putchar(c); 
        } 
    } 
    va_end(ap);
}

int main(void)
{ 
    myprintf("c\ts\nc\ts\n", '1', "hello,", '2', "this is my printf fucntion"); 
    return 0;
}


/* stdarg.h standard header
#ifndef _STDARG
#define _STDARG

typedef char *va_list;

#define va_arg(ap, T) \
            (* (T *)(((ap) += _Bnd(T, 3U)) - _Bnd(T, 3U)))

#define va_end(ap) (void)0

#define va_start(ap, A) \
            (void)((ap) = (char *)&(A) + _Bnd(A, 3U))

#define _Bnd(X, bnd) (sizeof (X) + (bnd) & ~(bnd))
                     // 以bnd = 3U来举例, 
                     // (sizeof (int) + (3U)) 的作用是将 x 的值加上3，
                     // 这样可以保证 x 的值至少是4的整数倍；
                     // ~(3U) 的作用是将最低两位清零，
                     // 这样可以保证 x 的值只有4的整数倍，没有其他的余数。所以，这种方法可以实现4字节对齐。

#endif
*/