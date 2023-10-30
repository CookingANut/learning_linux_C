#!/bin/bash

set -e
CTYPE="direct"

usage()
{
    echo "Usage: $0 [OPTIONS]"
    echo
    echo "Options:"
    echo "    --type=direct(default), link c source file and compile directly."
    echo "    --type=static, build libstack.a static library then compile."
    echo "    --type=shared, build libstack.so shared library then compile."
    echo 
    exit $1
}

bad_arg()
{
    echo "Unrecognized argument: $1" >&2
    usage 1
}

# Handle args
while [[ $# -gt 0 ]]; do
    case "$1" in
        --type=*)        CTYPE="${1#--type=}"           ;;
        -h|--help)       usage 0                        ;;
        -*)              bad_arg "$1"                   ;;
        *)               [[ $# -eq 1 ]] || bad_arg "$1" ;;
    esac
    shift
done

if [[ $CTYPE != "direct" && $CTYPE != "static" && $CTYPE != "shared" ]]; then
    echo "Unrecognized type: $CTYPE"
    usage 1
fi 

case $CTYPE in
    "direct")
        gcc -g linux_c_2.20.2.2_main.c stack/*.c -o main0 # export linux_c_2.20.2.2_main.o in current work directory
    ;;
                     
    "static")
        # pack to a staic library
        gcc -c stack/stack.c stack/push.c stack/pop.c stack/is_empty.c  # export stack.o, push.o ... in current work directory
        ar rs libstack.a stack.o push.o pop.o is_empty.o                # generate libstack.a static library, .a means archive
        # link libstack.a and linux_c_2.20.2.2_main.c
        gcc linux_c_2.20.2.2_main.c -L. -lstack -Istack -static -o main1
        # -L tells gcc where to find lib file, L. means current directory
        # -l tells gcc to link stack library
        # -I tells gcc where to find header
        # -static tells gcc to link staitc library libstack.a, otherwise it will search libstack.so
    ;;

    "shared")
        # pack to a shared library
        gcc -c -fPIC stack/stack.c stack/push.c stack/pop.c stack/is_empty.c  # generate object files
        # -f + compile options
        # PIC(Position Independent Code)
        gcc -shared -o libstack.so stack.o push.o pop.o is_empty.o  # generate libstack.so file
        gcc linux_c_2.20.2.2_main.c -g -L. -lstack -Istack -o main2
        cat /etc/ld.so.conf | grep "/home/daemonh/cproj/"
        if [[ $? -ne 0 ]]; then
            echo -e "/home/daemonh/cproj/\n" >> /etc/ld.so.conf
        else
            echo "PATH:/home/daemonh/cproj/ is in /etc/ld.so.conf already"
        fi
        # use ldd main2 to check what shared library main2 depends on
                # $ ldd main2
                # linux-vdso.so.1 (0x00007ffcabbfc000)
                # libstack.so => not found
                # libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fde90b0b000)
                # /lib64/ld-linux-x86-64.so.2 (0x00007fde90d13000)

        # use man ld.so to check shared libraries search path:
        # 1. find in environment variable LD_LIBRARY_PATH
        # 2. find in /etc/ld.so.cache(this cache is generated by /etc/ld.so.conf)
        # 3. /usr/lib
        # 4. during compilation, add absolute path, gcc main.c -g -L. -lstack -Istack -o main2 -Wl,-rpath,/home/daemonh/cproj
        # suggest to add absolute path eg. /home/daemonh/cproj/ to /etc/ld.so.conf
        # then use `sudo ldconfig -v` to check
    ;;
esac
exit $?