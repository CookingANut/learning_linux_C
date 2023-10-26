#include <stdio.h>

int greatest_common_divisor(int a, int b)
{
    while ( a % b != 0 )
    {   
        int temp = a;
        a = b;
        b = temp % b;
    }
    return b;
}

int fibonacci(int n)
{
    int temp_a = 1;
    int temp_b = 1;
    int result = 1;
    while (n >= 2)
    {
        result = temp_a + temp_b;
        temp_a = temp_b;
        temp_b = result;
        n = n -1;
    }
    return result;
}

int main()
{
    int a = 28;
    int b = 20;
    int k = 5;
    printf("the greatest common divisor between %d and %d is %d\n", a, b, greatest_common_divisor(a, b));
    printf("fibonacci(%d)=%d\n", k, fibonacci(k));
    return 0;
}