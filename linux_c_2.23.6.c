#include <stdio.h>
/*
2.23.6.1 answer:
const char **p;  p is a pointer of a pointer of const char
char *const *p;  p is a pointer of a const pointer of char
char **const p;  p is a const pointer of a pointer of char

 */
int main(int argc, char *argv[])
{ 
    int i; 
    printf("argc: %d\n", argc);
    for(i = 0; argv[i] != NULL; i++) 
        printf("argv[%d]=%s\n", i, argv[i]); 
        
    return 0;
}