# librecrt/posix/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude -I../crt/include -L../bin/libc-crt -lcrt -nostdlib
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,../bin/obj/posix/%.o,$(SRCS))
LIB = ../bin/libc-posix/libposix.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p ../bin/libc-posix
	ar rcs $@ $^

../bin/obj/posix/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
