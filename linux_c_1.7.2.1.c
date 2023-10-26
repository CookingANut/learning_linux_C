#include <stdio.h>

struct complex_struct
{
    double x, y;
};

void print_complex_struct(const struct complex_struct cs)
{
    if (cs.x > 0 || cs.x < 0)
    {   
        if (cs.y > 0)
            printf("%f+%fi\n", cs.x, cs.y);
        else
        {
            if (cs.y < 0)
                printf("%f%fi\n", cs.x, cs.y);
            else
                printf("%f\n",cs.x);
        
        }
    }
    else
    {
        if (cs.y > 0)
            printf("%fi\n", cs.y);
        if (cs.y < 0)
            printf("%fi\n", cs.y);
        else
            printf("%f\n", cs.x);
    }
}

int main()
{
    struct complex_struct cs = {5.0, 0};
    print_complex_struct(cs);
}