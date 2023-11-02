sources = main.c stack.c maze.c
include $(sources:.c=.d) # just like including files into this Makefile 

all: main

main: main.o stack.o maze.o 
	gcc $^ -o $@

clean: 
	@echo "cleanning project" 
	-${RM} main *.o *.d
	@echo "clean completed"

.PHONY: clean
# using pattern rule
# use gcc -MM to check file dependencies
%.d: %.c 
	set -e; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	${RM} $@.$$$$ \										