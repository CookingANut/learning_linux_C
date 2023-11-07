# macro notes

``` format tab
#       : 用于创建字符串, #运算符后面应该跟一个形参,中间可以有空格或Tab
            #define STR(s) # s
            STR(hello world)

##      : 把前后两个预处理Token连接成一个预处理Token，和#运算符不同，##运算符不仅限于函数式宏定义，变量式宏定义也可以用
            #define CONCAT(a, b) a##b
            CONCAT(con, cat)

            #define HASH_HASH # ## #

...     : 表示可变参数, 在宏定义中, 可变参数的部分用__VA_ARGS__表示, 实参中对应...的几个参数可以看成一个参数替换到宏定义中__VA_ARGS__所在的地方
            #define showlist(...) printf(#__VA_ARGS__)
            #define report(test, ...) ((test)?printf(#test):printf(__VA_ARGS__))
            showlist(The first, second, and third items.);
            report(x>y, "x is %d but y is %d", x, y);

__FILE__: 展开为当前源文件的文件名，是一个字符串

__LINE__: 展开为当前代码行的行号，是一个整数

__func__: 打印出当前函数名
```
