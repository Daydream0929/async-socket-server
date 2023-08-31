# Makefile for the C code in async-socket-server.
# This code is in the public domain.
CC = gcc
CCFLAGS = -std=gnu99 -Wall -O3 -g -DNDEBUG -pthread
LDFLAGS = -lpthread -pthread


EXECUTABLES = \
	sequential_server 

all: $(EXECUTABLES)

sequential_server: utils.c sequential_server.c
	$(CC) $(CCFLAGS) $^ -o $@ $(LDFLAGS)


.PHONY: clean format

clean:
	rm -f $(EXECUTABLES) *.o

format:
	clang-format -style=file -i *.c *.h