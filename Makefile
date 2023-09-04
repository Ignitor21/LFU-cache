CC=g++
CFLAGS= -std=c++20 -c -Wall -g

all: lfu
	./lfu

lfu: main.o lfu.o
	$(CC) lfu.o main.o -o lfu

main.o: lfu_src/main.cpp
	$(CC) $(CFLAGS) lfu_src/main.cpp

lfu.o: lfu_src/lfu.cpp
	$(CC) $(CFLAGS) lfu_src/lfu.cpp

clean:
	rm *.o lfu