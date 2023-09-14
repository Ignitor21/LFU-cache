CC=g++
CFLAGS= -c -Wall -O2
DEBUGFLAG=-c -Wall -O0 -g -D DEBUG

all: build_lfu execute clean

execute: 
	./lfu

debug: lfu_debug.o 
	$(CC) lfu_debug.o -o lfu_debug

build_lfu: lfu.o
	$(CC) lfu.o -o lfu

lfu.o: lfu_src/lfu.cpp
	$(CC) $(CFLAGS) lfu_src/lfu.cpp

lfu_debug.o: lfu_src/lfu.cpp
	$(CC) $(DEBUGFLAG) lfu_src/lfu.cpp -o lfu_debug.o

build_perfect: perfect.o
	$(CC) perfect.o -o perfect

perfect.o: perfect_src/perfect.cpp
	$(CC) $(CFLAGS) perfect_src/perfect.cpp -o perfect.o

test: build_lfu build_perfect clean
	 ./tests/bash.sh

clean:
	rm *.o