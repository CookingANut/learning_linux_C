/* main.c */
#include <stdio.h>
#include "ret_ptr.h"

int main(void)
{ 
    printf("%s %s\n", get_a_day(0), get_a_day(1)); 
    /*
    输出是sunday sunday, 因为buf是一个静态数组， 执行完get_a_day(1) 是Monday，此时buf指向Monday，
    执行完get_a_day(0)后，buf指向Sunday，
    printf调用后，直接显示的就是buf此时的指向，即Sunday Sunday
    */
    return 0;
}