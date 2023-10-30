#include <stdio.h>

/*
 *  __asm__(assembler template 
 *  : output operands               // optional
 *  : input operands                //optional 
 *  : list of clobbered registers   //optional
 * );
 */

int main() 
{ 
    int a = 10, b;
    __asm__(
        "movl %1, %%eax\n\t"    /* Assembly Instructions */
        "movl %%eax, %0\n\t"    /* Assembly Instructions */
        : "=r"(b)               /* output, =%0 */
        : "r"(a)                /* input, =%1 */
        : "%eax"                /* clobbered register */
    );
    printf("Result: %d, %d\n", a, b); 
    
    return 0;
}