
#include <unistd.h>
#include <stdint.h>
#include <universe.h>

static void *heap_end = 0;

int brk(void *addr)
{
    heap_end = (void*) linux_syscall(SYS_BRK, addr, 0, 0, 0, 0);
    return 0;
}

void *sbrk(intptr_t increment)
{
    brk(0);
    int r = brk(heap_end + increment);
    return (r < 0) ? r : heap_end;
}

