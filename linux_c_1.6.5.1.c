#include <stdio.h>

int main(void)
{ 
    int i, j; 
    for (i=1; i<=9; i++) 
    { 
        for (j=1; j<=9; j++)
            if (j <= i)
                printf("%d\t", i*j); 
        printf("\n"); 
    } 
    return 0;
}