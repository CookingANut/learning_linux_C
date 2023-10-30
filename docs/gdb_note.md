# GDB notes

``` format tab
backtrace(bt)                           : 查看各级函数调用及参数
finished                                : 连续运行到当前函数返回为止，然后停下来等待命令
frame(f) + frame index                  : 选择栈帧
info(i) locals                          : 查看当前栈帧局部变量的值
list(l)                                 : 列出源代码，接着上次的位置往下列，每次列10行
list + row number                       : 列出从第几行开始的源代码
next(n)                                 : 执行下一行语句
print(p)                                : 打印表达式的值，通过表达式可以修改变量的值或者调用函数
quit(q)                                 : 退出gdb调试环境
set var                                 : 修改变量的值
start                                   : 开始执行程序，停在main函数第一行语句前面等待命令
step(s)                                 : 执行下一行语句，如果有函数调用则进入到函数中

break(b) + row number                   :  在某一行设置断点
break + function name                   : 在某个函数开头设置断点
break ... if ...                        : 设置条件断点
continue(c)                             : 从当前位置开始连续运行程序
delete breakpoints + breakpoints number : 删除断点
display + variable name                 : 跟踪查看某个变量，每次停下来都显示它的值
disable + breakpoints number            : 禁用断点
enable + breakpoints numbder            : 启用断点
info(i) breakpoints                     : 查看当前设置了哪些断点
run(r)                                  : 从头开始连续运行程序
undisplay + track number                : 取消跟踪显示

watch                                   : 设置观察点
info(i) watchpoints                     : 查看当前设置了哪些观察点
x                                       : 从某个位置开始打印存储单元的内容，全部当成字节来看，而不区分哪个字节属于哪个变量
x/20 $esp                               : 查看$esp储存的值的内存地址开始的20个32位数

disassemble                             : 反汇编当前函数或者指定的函数
si                                      : 一条指令一条指令地单步调试
info registers                          : 显示所有寄存器的当前值
p $esp                                  : 打印esp寄存器的值, gdb中表示寄存器名时前面要加个$
```
