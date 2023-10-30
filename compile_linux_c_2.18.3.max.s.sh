#!/bin/bash

if [ ! -e ./linux_c_2.18.3.max ]; then
    # assembly
    as ./linux_c_2.18.3.max.s -o ./linux_c_2.18.3.max.o 
    # link
    ld ./linux_c_2.18.3.max.o -o ./linux_c_2.18.3.max
fi 
# execute
./linux_c_2.18.3.max

echo "the max numebr is $?"

# obj file
readelf -a ./linux_c_2.18.3.max.o # Executable and linking format (ELF)
                                  # if only need to check symbol table, use:
                                  # `readelf  -s` or `nm` command
hexdump -C linux_c_2.18.3.max.o
objdump -d linux_c_2.18.3.max.o  # disassemble

# exe file
readelf -a ./linux_c_2.18.3.max
hexdump -C linux_c_2.18.3.max
objdump -d linux_c_2.18.3.max  # disassemble
# use objdump -dS if you add -g option in gcc
# or directly use gcc -S main.c to generate main.s assemble file