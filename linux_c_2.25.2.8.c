#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef MYCP
#define MYCP
#define help(rc) \
do { \
    printf("arguments:\n"); \
    printf("    args[1]: source file path\n"); \
    printf("    args[2]: destination file path\n"); \
    printf("e.g.,\n"); \
    printf("    ./mycp ${src_file} ${dest_file}\n"); \
    exit(rc); \
} while (0)
# endif

int main(int argc, char *argv[])
{ 
    if (argc == 1)
        help(1);

    for (int i = 0; argv[i]!= NULL && i <=2; i++) {
        
        if (! strcmp(argv[i], "-h") || ! strcmp(argv[i], "--help")) {
            help(0);
        };
    };

    FILE *SRC;
    FILE *DEST;
    char string[10];

    if ( (SRC = fopen(argv[1], "r")) == NULL) { 
        perror("Error occur, open source file"); 
        exit(1); 
    }

    if ( (DEST = fopen(argv[2], "w")) == NULL) { 
        perror("Error occur, write target file"); 
        exit(1); 
    }

    while ( (fgets(string, 10, SRC)) != NULL)
        fputs(string, DEST); 

    printf("Copied: %s -> %s\n", argv[1], argv[2]);
    fclose(SRC);
    fclose(DEST);

    return 0;
}

