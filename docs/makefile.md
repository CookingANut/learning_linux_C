# MakeFile notes

``` basic format
target ... : prerequisites ... 
    command1 
    command2
```

``` notes
.PHONY: clean       # 声明一个伪目标clean
y := $(x):          # 遇到变量时立即展开
objects += $(foo)   # 给变量追加值

$@                  # 表示规则中的目标
$<                  # 表示规则中的第一个条件
$?                  # 表示规则中所有比目标新的条件，组成一个列表，以空格分隔
$^                  # 表示规则中的所有条件，组成一个列表，以空格分隔
```

``` variables
AR                  # 静态库打包命令的名字，缺省值是ar。
ARFLAGS             # 静态库打包命令的选项，缺省值是rv。
AS                  # 汇编器的名字，缺省值是as。
ASFLAGS             # 汇编器的选项，没有定义。
CC                  # C编译器的名字，缺省值是cc。
CFLAGS              # C编译器的选项，没有定义。
CXX                 # C++编译器的名字，缺省值是g++。
CXXFLAGS            # C++编译器的选项，没有定义。
CPP                 # C预处理器的名字，缺省值是$(CC) -E。
CPPFLAGS            # C预处理器的选项，没有定义。
LD                  # 链接器的名字，缺省值是ld。
LDFLAGS             # 链接器的选项，没有定义。
TARGET_ARCH         # 和目标平台相关的命令行选项，没有定义。
OUTPUT_OPTION       # 输出的命令行选项，缺省值是-o $@。
LINK.o              # 把.o文件链接在一起的命令行，缺省值是$(CC) $(LDFLAGS) $(TARGET_ARCH)。
LINK.c              # 把.c文件链接在一起的命令行，缺省值是$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)$(TARGET_ARCH)。
LINK.cc             # 把.cc文件（C++源文件）链接在一起的命令行，缺省值是$(CXX) $(CXXFLAGS) $(CPPFLAGS)$(LDFLAGS) $(TARGET_ARCH)。
COMPILE.c           # 编译.c文件的命令行，缺省值是$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c。
COMPILE.cc          # 编译.cc文件的命令行，缺省值是$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c。
RM                  # 删除命令的名字，缺省值是rm -f
```
