# unix std lib

## open/close

``` c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
返回值：成功返回新分配的文件描述符，出错返回-1并设置errno

必选项：以下三个常数中必须指定一个，且仅允许指定一个。
O_RDONLY 只读打开
O_WRONLY 只写打开
O_RDWR 可读可写打开

可选项：
O_APPEND 表示追加。如果文件已有内容，这次打开文件所写的数据附加到文件的末尾而不覆盖原来的内容。
O_CREAT 若此文件不存在则创建它。使用此选项时需要提供第三个参数mode，表示该文件的访问权限。
O_EXCL 如果同时指定了O_CREAT，并且文件已存在，则出错返回。
O_TRUNC 如果文件已存在，并且以只写或可读可写方式打开，则将其长度截断（Truncate）为0字节。
O_NONBLOCK 对于设备文件，以O_NONBLOCK方式打开可以做非阻塞I/O（Nonblock I/O）
```

```c
#include <unistd.h>
int close(int fd);
返回值：成功返回0，出错返回-1并设置errno
```
