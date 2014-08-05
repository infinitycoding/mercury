SRCS = $(shell find -name '*.c')
OBJS = $(addsuffix .o,$(basename $(SRCS)))



L_CFLAGS = -m32 -Wall -g -nostdinc -fno-stack-protector -fno-builtin -fno-builtin-log -Wimplicit-function-declaration -nostdinc -I include
ASFLAGS =-felf32


CC = i686-universe-gcc
ASM = nasm
LD = i686-universe-ld


all: libc.a

libc.a: $(OBJS)
	@ar -rcs $@ $^

%.o: %.c
	$(CC) ${CFLAGS} $(L_CFLAGS) -c -o $@ $^

clean:
	@rm $(OBJS) -f
	@rm libc.a -f

.PHONY: clean

