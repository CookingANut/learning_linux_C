#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp = fopen("/etc/", "r+");
    if (fp == NULL) { 
        perror("Open /etc/shadow"); 
        exit(1);
    }
}
