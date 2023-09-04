# Makefile for the C code in async-socket-server.
# This code is in the public domain.
CC = gcc
CXX = g++
CCFLAGS = -std=gnu99 -Wall -O3 -g -DNDEBUG -pthread
LDFLAGS = -lpthread -pthread


EXECUTABLES = \
	sequential_server \
	thread_server \
	test_thread_pool_cpp

all: $(EXECUTABLES)

sequential_server: utils.c sequential_server.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LDFLAGS)

thread_server: utils.c thread_server.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LDFLAGS)

test_thread_pool_cpp: thread_pool.cpp test_thread_pool_cpp.cpp
	$(CXX) $(CCFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: clean format

clean:
	rm -f $(EXECUTABLES) *.o

format:
	clang-format -style=file -i *.c *.h *.cpp