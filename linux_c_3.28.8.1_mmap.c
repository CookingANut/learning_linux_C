#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> 

int main(void) 
{
    int *p;
    int fd = open("hello.txt", O_RDWR);
    if (fd < 0) {
        perror("open hello");
        exit(1);
    }
    p = mmap(NULL, 6, PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    close(fd);
    /*
    整数在内存中是以小端字节序(little-endian)的方式存储的。
    小端字节序是指最低有效字节(Least Significant Byte，LSB)存储在最低的地址上，
    最高有效字节(Most Significant Byte，MSB)存储在最高的地址上。
    0x30313233 是一个 4 字节的整数，
    其中 0x30 是最高有效字节，0x33 是最低有效字节。
    当这个整数以小端字节序存储在内存中时，0x33 会被存储在最低的地址上，
    0x30 会被存储在最高的地址上。
    */
    p[0] = 0x30313233;
    munmap(p, 6);
    return 0;
}
