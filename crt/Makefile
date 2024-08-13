# librecrt/crt/Makefile

CC = gcc
CFLAGS = -Wall -Iinclude -nostdlib -fno-builtin
SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,../bin/obj/crt/%.o,$(SRCS))
LIB = ../bin/libc-crt/libcrt.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJS)
	@mkdir -p ../bin/libc-crt
	ar rcs $@ $^

../bin/obj/crt/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)
