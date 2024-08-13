# librecrt/Makefile

.PHONY: all clean crt posix

all: crt posix libc-all

crt:
	$(MAKE) -C crt

posix: crt
	$(MAKE) -C posix

libc-all: posix
	@mkdir -p bin/libc-all
	ar rcs bin/libc-all/libc-all.a bin/libc-crt/libcrt.a bin/libc-posix/libposix.a

clean:
	$(MAKE) -C crt clean
	$(MAKE) -C posix clean
	rm -rf bin/libc-all
