CC=g++
CFLAGS=-std=c++20 -c -Wall -O2 
DEBUGFLAG=-std=c++20 -c -Wall -O0 -g -D DEBUG

all: build execute clean

execute: 
	./lfu

debug: lfu_debug.o clean
	$(CC) lfu_debug.o -o lfu_debug

build: lfu.o
	$(CC) lfu.o -o lfu

lfu.o: lfu_src/lfu.cpp
	$(CC) $(CFLAGS) lfu_src/lfu.cpp

lfu_debug.o: lfu_src/lfu.cpp
	$(CC) $(DEBUGFLAG) lfu_src/lfu.cpp -o lfu_debug.o

clean:
	rm *.o lfu