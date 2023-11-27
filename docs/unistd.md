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
// files descriptor
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#include <unistd.h>
int close(int fd);
返回值：成功返回0，出错返回-1并设置errno
```

## read/write

```c
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
返回值：成功返回读取的字节数，出错返回-1并设置errno，如果在调read之前已到达文件末尾，则这次read返回0

#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
返回值：成功返回写入的字节数，出错返回-1并设置errno
```

## lseek

```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
```

## fcntl

```c
#include <unistd.h>
#include <fcntl.h>
int fcntl(int fd, int cmd);
int fcntl(int fd, int cmd, long arg);
int fcntl(int fd, int cmd, struct flock *lock);
```

## ioctl

```c
#include <sys/ioctl.h>
int ioctl(int d, int request, ...);
```

## mmap

```c
#include <sys/mman.h> 
void *mmap(void *addr, size_t len, int prot, int flag, int filedes, off_t off); 
int munmap(void *addr, size_t len);

addr:
如果addr参数为NULL，内核会自己在进程地址空间中选择合适的地址建立映射。
如果addr不是NULL，则给内核一个提示，应该从什么地址开始映射，
内核会选择addr之上的某个合适的地址开始映射。建立映射后，真正的映射首地址通过返回值可以得到。

len:
len参数是需要映射的那一部分文件的长度。

prot:
PROT_EXEC表示映射的这一段可执行，例如映射共享库
PROT_READ表示映射的这一段可读
PROT_WRITE表示映射的这一段可写
PROT_NONE表示映射的这一段不可访问

flag:
MAP_SHARED多个进程对同一个文件的映射是共享的，一个进程对映射的内存做了修改，另一个进程也会看到这种变化。
MAP_PRIVATE多个进程对同一个文件的映射不是共享的，一个进程对映射的内存做了修改，另一个进程并不会看到这种变化，也不会真的写到文件中去。

off:
off参数是从文件的什么位置开始映射，必须是页大小的整数倍（在32位体系统结构上通常是4K）。
filedes是代表该文件的描述符。
```
