#include <stdio.h>

int main()
{
    int i = 0xcffffff3;
    printf("%x\n", 0xcffffff3>>2);
    printf("%x\n", i>>2);
    printf("%zd\n", sizeof(unsigned int));
    printf("%x\n", (~0 << 8));

    int a = 3 , b = 4;
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
    printf("%x, %x\n", a, b);


}