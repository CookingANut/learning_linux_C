#include <stdio.h>

char *shrink_space(char *dest, const char *src, size_t n)
{
    int i;
    int add_space = 0;
    int dest_idx = 0;

    for (i = 0 ; i < n && src[i] != '\0' ; i++){
        switch (src[i]){
        case '\t':
            if (add_space)
                continue;
            else
                add_space = 1;
            break;
        case ' ':
            if (add_space)
                continue;
            else
                add_space = 1;
            break;
        case '\n':
            if (add_space)
                continue;
            else
                add_space = 1;
            break;
        case '\r':
            if (add_space)
                continue;
            else
                add_space = 1;
            break;
        default:
            if (add_space){
                dest[dest_idx] = ' ';
                dest_idx ++;
            };
            dest[dest_idx] = src[i];
            dest_idx++;
            add_space = 0;
            break;
        };
    };
    for ( ; i < n ; i++)
        dest[dest_idx] = '\0';

    return dest;
}

int main()
{
    char src_test[] = "This is a test\t\nstring   \r\n!";
    char dest_test[50];
    printf("%lu\n", sizeof(src_test));
    printf("%s\n", shrink_space(dest_test, src_test, 29));

    return 0;
}