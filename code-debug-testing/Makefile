CC = riscv64-linux-musl-gcc
CFLAGS = -Wall -Werror -O0 -fno-omit-frame-pointer -ggdb -g3 -Wa,--gen-debug,-D,--nocompress-debug-sections
TARGETS = first_process second_process

all: $(TARGETS)

first_process: first_process.c
	$(CC) $(CFLAGS) -o $@ $<

second_process: second_process.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)