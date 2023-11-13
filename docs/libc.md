# C Stdlib

## 初始化字符串

``` c
#include <string.h>
void *memset(void *s, int c, size_t n); 
返回值：s指向哪，返回的指针就指向哪
```

## 取字符串长度

``` c
size_t strlen(const char *s);
返回值：字符串的长度
```

## 拷贝字符串

``` c
#include <string.h>
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
返回值：dest指向哪，返回的指针就指向哪
```

``` c
#include <string.h>
char *strdup(const char *s);
返回值：指向新分配的字符串
```

## 连接字符串

``` c
#include <string.h>
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
返回值：dest指向哪，返回的指针就指向哪
```

## 比较字符串

``` c
#include <string.h>
int memcmp(const void *s1, const void *s2, size_t n);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
返回值：负值表示s1小于s2，0表示s1等于s2，正值表示s1大于s2
```

## 搜索字符串

``` c
#include <string.h>
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
返回值：如果找到字符c，返回字符串s中指向字符c的指针，如果找不到就返回NULL
```

``` c
#include <string.h>
char *strstr(const char *haystack, const char *needle);
返回值：如果找到子串，返回值指向子串的开头，如果找不到就返回NULL
```

## 分割字符串

``` c
#include <string.h>
char *strtok(char *str, const char *delim);
char *strtok_r(char *str, const char *delim, char **saveptr);
返回值：返回指向下一个Token的指针，如果没有下一个Token了就返回NULL
```

## 打开/关闭文件

```c
#include <stdio.h>
FILE *fopen(const char *path, const char *mode);
返回值：成功返回文件指针，出错返回NULL并设置errno
```

```c
#include <stdio.h>
int fclose(FILE *fp);
返回值：成功返回0，出错返回EOF并设置errno
/* End of file character. Some things throughout the library rely on this being -1. */
#ifndef EOF
# define EOF (-1)
#endif
```

## 错误输出

``` c
#include <stdio.h>
void perror(const char *s);
```

``` c
#include <string.h>
char *strerror(int errnum);
返回值：错误码errnum所对应的字
```

## 以字节为单位的I/O函数

```c
#include <stdio.h>
int fgetc(FILE *stream);
int getchar(void);
返回值：成功返回读到的字节，出错或者读到文件末尾时返回EOF
```

```c
#include <stdio.h>
int fputc(int c, FILE *stream);
int putchar(int c);
返回值：成功返回写入的字节，出错返回EOF
```
