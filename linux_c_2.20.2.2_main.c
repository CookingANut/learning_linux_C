/* main.c */
#include <stdio.h>
#include "stack/stack.h"

int main(void)
{ 
    push('a'); 
    push('b'); 
    push('c'); 
    while(!is_empty()) 
        putchar(pop()); 
    putchar('\n'); 
    
    return 0;
}