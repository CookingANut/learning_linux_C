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

``` <!-- language: lang-none -->
mode option
"r"   :   只读，文件必须已存在
"w"   :   只写，如果文件不存在则创建，如果文件已存在则把文件长度截断（Truncate）为0字节再重新写，也就是替换掉原来的文件内容
"a"   :   只能在文件末尾追加数据，如果文件不存在则创建
"r+"  :   允许读和写，文件必须已存在
"w+"  :   允许读和写，如果文件不存在则创建，如果文件已存在则把文件长度截断为0字节再重新写
"a+"  :   允许读和追加数据，如果文件不存在则创建
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

## 操作读写位置的函数

```c
#include <stdio.h>
int fseek(FILE *stream, long offset, int whence);
返回值：成功返回0，出错返回-1并设置errno
whence:
SEEK_SET 从文件开头移动offset个字节
SEEK_CUR 从当前位置移动offset个字节
SEEK_END 从文件末尾移动offset个字节

long ftell(FILE *stream);
返回值：成功返回当前读写位置，出错返回-1并设置errno

void rewind(FILE *stream);
把读写位置移到文件开头
```

## 以字符串为单位的I/O函数

```c
#include <stdio.h>
char *fgets(char *s, int size, FILE *stream);
char *gets(char *s);
返回值：成功时s指向哪返回的指针就指向哪，出错或者读到文件末尾时返回NULL
```

```c
#include <stdio.h>
int fputs(const char *s, FILE *stream);
int puts(const char *s);
返回值：成功返回一个非负整数，出错返回EOF
```

## 以记录为单位的I/O函数

```c
#include <stdio.h>
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
返回值：读或写的记录数，成功时返回的记录数等于nmemb，出错或读到文件末尾时返回的记录数小于nmemb，也可能返回0
```

## 格式化I/O函数

```c
#include <stdio.h>
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);

#include <stdarg.h>
int vprintf(const char *format, va_list ap);
int vfprintf(FILE *stream, const char *format, va_list ap);
int vsprintf(char *str, const char *format, va_list ap);
int vsnprintf(char *str, size_t size, const char *format, va_list ap);
返回值：成功返回格式化输出的字节数（不包括字符串的结尾'\0'），出错返回一个负值
```

```c
#include <stdio.h>
int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int sscanf(const char *str, const char *format, ...);

#include <stdarg.h>
int vscanf(const char *format, va_list ap);
int vsscanf(const char *str, const char *format, va_list ap);
int vfscanf(FILE *stream, const char *format, va_list ap);
返回值：返回成功匹配和赋值的参数个数，成功匹配的参数可能少于所提供的赋值参数，返回0表示一个都不匹配，
出错或者读到文件或字符串末尾时返回EOF并设置errno
```

``` <!-- language: lang-none -->
printf 转换说明的可选项

#       : 八进制前面加0（转换字符为o），十六进制前面加0x（转换字符为x）或0X（转换字符为X）。
          例：printf("%#x", 0xff);
          输出：0xff

-       : 格式化后的内容居左，右边可以留空格。

width   : 用一个整数指定格式化后的最小长度，如果格式化后的内容没有这么长，可以在左边留空格，如果前面指定了-号
          就在右边留空格。宽度有一种特别的形式，不指定整数值而是写成一个*号，表示取一个int型参数作为宽度。
          例：printf("-%10s-", "hello");
          输出：-     hello-
          例：printf("-%-*s-", 10, "hello");
          输出：-hello   
            -
.       : 用于分隔上一条提到的最小长度和下一条要讲的精度。

Accuracy: 用一个整数表示精度，对于字符串来说指定了格式化后保留的最大长度，
          对于浮点数来说指定了格式化后小数点右边的位数，对于整数来说指定了格式化后的最小位数。
          精度也可以不指定整数值而是写成一个*号，表示取下一个int型参数作为精度。
          例: printf("%.4s", "hello")；
          输出：hell
          例：printf("-%6.4d-",100); 
          输出：-   0100-
          例：printf("-%*.*f-", 8, 4, 3.14)
          输出：-  3.1400-

lenth   : 对于整型参数，hh、h、l、ll分别表示是char、short、long、long long型的字长，
          至于是有符号数还是无符号数则取决于转换字符；对于浮点型参数，L表示long double型的字长。
          例: printf("%hhd", 255)
          输出：-1
```

``` <!-- language: lang-none -->
printf的转换字符

d       : 取int型参数格式化成有符号十进制表示，如果格式化后的位数小于指定的精度，就在左边补0
          例：printf("%.4d", 100)
          输出：0100

ouxX    : 取unsigned int型参数格式化成无符号八进制（o）、
          十进制（u）、
          十六进制（x或X）表示，x表示十六进制数字用小写abcdef，X表示十六进制数字用大写ABCDEF，
          如果格式化后的位数小于指定的精度，就在左边补0。
          例：printf("%#X", 0xdeadbeef)；
          输出：0XDEADBEEF
          例：printf("%hhu",-1)
          输出：255

c       : 取int型参数转换成unsigned char型，格式化成对应的ASCII码字符。
          例：printf("%c", 256+'A')；
          输出：A
s       : 取const char *型参数所指向的字符串格式化输出，遇到'\0'结束，或者达到指定的最大长度（精度）结束。
          例: printf("%.4s", "hello")；
          输出：hell

p       : 取void *型参数格式化成十六进制表示。相当于%#x
          例：printf("%p", main)；
          输出： main函数的首地址0x80483c4

f       : 取double型参数格式化成[-]ddd.ddd这样的格式，小数点后的默认精度是6位。
          例：printf("%f", 3.14)；
          输出：3.140000
          例：printf("%f",0.00000314)；
          输出：0.000003

eE      : 取double型参数格式化成[-]d.ddde±dd（转换字符是e）或[-]d.dddE±dd（转换字符是E）这样的格式，
          小数点后的默认精度是6位，指数至少是两位。
          例：printf("%e", 3.14)；
          输出：3.140000e+00

gG      : 取double型参数格式化，精度是指有效数字而非小数点后的数字，默认精度是6。
          如果指数小于-4或大于等于精度就按%e（转换字符是g）或%E（转换字符是G）格式化，否则按%f格式化。
          小数部分的末尾0去掉，如果没有小数部分，小数点也去掉。
          例：printf("%g", 3.00)
          输出：3
          例：printf("%g",0.00001234567)
          输出：1.23457e-05

%       : 格式化成一个%
          例子：printf("%%")；
          输出：%
```

## C标准库的I/O缓冲区

``` c
#include <stdio.h>
int fflush(FILE *stream);
返回值：成功返回0，出错返回EOF并设置errno
```
