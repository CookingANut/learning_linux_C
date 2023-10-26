#include <stdio.h>
#include <stdlib.h>
#define N 1000000

int a[N];

void gen_random(int upper_bound)
{
    int i;
    for (i = 0; i < N; i++)
        a[i] = rand() % upper_bound;
}

int show_quantities(int value)
{
    int count = 0, i;
    for (i = 0; i < N; i++)
        if (a[i] == value)
            ++count;
    return count;
}

float show_percentage(int value)
{
    int count = 0, i;
    for (i = 0; i < N; i++)
        if (a[i] == value)
            ++count;
    return count / (float)N * 100;
}


int main(void)
{
    int i;
    gen_random(10); 
    printf("value\tquantities\tpercentage\n"); 
    for (i = 0; i < 10; i++)
        printf("%d\t%d\t\t%.3f%%\n", i, show_quantities(i), show_percentage(i));
    return 0;
}
