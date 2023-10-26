#include <stdio.h>
#include <math.h>

int diamond(int index, char symbol)
{
    if (index % 2)
    {
        if (index == 1)
        {
            printf("%c\n", symbol);
            return 1;
        }
    
        int middle = (1 + index) / 2;

        for (int row=1; row <= index; row++)
        {
            for (int col=1; col <= index; col++)
            {
                if (row == middle || col == middle)
                {
                    printf("%c\t", symbol);
                    continue;
                }
                if ((fabs(row - middle) + fabs(col - middle)) >= middle)
                    printf("\t");
                else
                    printf("%c\t", symbol);
            }
            printf("\n");
        }
        return 0;
    }
    else
    {
        printf("Only support odd index diamond, exit.\n");
        return 0;
    }
}


int main()
{
    diamond(7,'O');
    return 0;
}