CC		=	gcc
CFLAGS	=	-O3 -march=native -Wall 

all: memoryallocator
	

run: all
	echo "+++++ Running Example: +++++"
	./memoryallocator
	./memoryallocator 500

memoryallocator : memoryallocator.c
	$(CC) $< $(CFLAGS) -o $@
