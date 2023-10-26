#include <stdio.h>

int is_leap_year(int year)
{
    if ((!year % 4 && year % 100) || (!year % 400))
    {
        printf("Y%d is leap year.\n", year);
        return 1;
    }
    else
    {
        printf("Y%d is not leap year.\n", year);
        return 0;
    }
}


int main()
{
    return is_leap_year(2023);
}
