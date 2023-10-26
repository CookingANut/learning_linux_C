#include <stdio.h>

int greatest_common_divisor(int a, int b)
{
    if (a % b == 0)
        return b;
    else
        return greatest_common_divisor(b, a%b);
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
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