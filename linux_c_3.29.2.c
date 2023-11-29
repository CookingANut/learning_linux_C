#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */

/*
opendir(3)/readdir(3)/closedir(3)用于遍历目录数据块中的记录。
opendir打开一个目录，返回一个DIR *指针代表这个目录，它是一个类似FILE *指针的句柄，
closedir用于关闭这个句柄，把DIR*指针传给
readdir读取目录数据块中的记录，每次返回一个指向struct dirent的指针，反复读就可以遍历所有记录，所有记录遍历完之后readdir返回NULL。

结构体struct dirent的定义如下：
struct dirent 
{ 
    ino_t d_ino;                //inode number 
    off_t d_off;                //offset to the next dirent 
    unsigned short d_reclen;    //length of this record 
    unsigned char d_type;       //type of file  
    char d_name[256];           //filename 
};
*/
void dirwalk(char *dir, void (*fcn)(char *)) {
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if ((dfd = opendir(dir)) == NULL) {
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }

    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
            continue; /* skip self and parent */

        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
            fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->d_name);
        else {
            sprintf(name, "%s/%s", dir, dp->d_name);
            (*fcn)(name);
        }
    }

    closedir(dfd);
}

/* fsize: print the size and name of file "name" */
void fsize(char *name) {
    struct stat stbuf;

    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    if ((stbuf.st_mode & __S_IFMT) == __S_IFDIR)
        dirwalk(name, fsize);

    printf("%8ld %s\n", stbuf.st_size, name);
}

int main(int argc, char **argv) {
    if (argc == 1) /* default: current directory */
        fsize(".");
    else
        while (--argc > 0)
            fsize(*++argv);

    return 0;
}
