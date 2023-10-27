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
hexdump -C linux_c_2.18.3.max.o
objdump -d linux_c_2.18.3.max.o  # disassemble

# exe file
readelf -a ./linux_c_2.18.3.max
hexdump -C linux_c_2.18.3.max
objdump -d linux_c_2.18.3.max  # disassemble