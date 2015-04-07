#ifndef _linux_syscall_h_
#define _linux_syscall_h_

#include <stdint.h>

// Linux Syscalls
#define SYS_EXIT        1
#define SYS_FORK        2
#define SYS_READ        3
#define SYS_WRITE       4
#define SYS_OPEN        5

#define SYS_CLOSE       6
#define SYS_WAITPID     7
#define SYS_CREAT       8
#define SYS_LINK        9

#define SYS_UNLINK      10
#define SYS_EXECVE      11
#define SYS_CHDIR       12
#define SYS_TIME        13
#define SYS_MKNOD       14

#define SYS_CHMOD       15
#define SYS_LCHOWN      16
#define SYS_BREAK       17
#define SYS_STAT        18
#define SYS_LSEEK       19

#define SYS_GETPID      20
#define SYS_MOUNT       21
#define SYS_UMOUNT      22
#define SYS_SETUID      23
#define SYS_GETUID      24

#define SYS_STIME       25
#define SYS_PTRACE      26
#define SYS_ALARM       27
#define SYS_FSTAT       28
#define SYS_PAUSE       29

#define SYS_UTIME       30
#define SYS_STTY        31
#define SYS_GTTY        32
#define SYS_ACCESS      33
#define SYS_NICE        34

#define SYS_FTIME       35
#define SYS_SYNC        36
#define SYS_KILL        37
#define SYS_RENAME      38
#define SYS_MKDIR       39

#define SYS_RMDIR       40
#define SYS_DUP         41
#define SYS_PIPE        42
#define SYS_TIMES       43
#define SYS_PROF        44

#define SYS_BRK         45
#define SYS_SETGID      46
#define SYS_GETGID      47
#define SYS_SIGNAL      48
#define SYS_GETEUID      49

#define SYS_READDIR     50 // at 141 TODO
#define SYS_GETDENTS    50 // a???
// TODO
#define SYS_GETCWD      54
#define SYS_SHMGET		55
#define SYS_SHMCTL		56
#define SYS_SHMAT		57
#define SYS_SHMDT		58

static inline uint32_t linux_syscall(uint32_t function, uint32_t ebx, uint32_t ecx, uint32_t edx, uint32_t esi, uint32_t edi)
{
    uint32_t retv = 0;
    asm volatile(
        "push %ebx;"
        "push %esi;"
        "push %edi"
    );

    asm volatile(
        "int $128;"
        "pop %%edi;"
        "pop %%esi;"
        "pop %%ebx;"
        : "=a" (retv) : "a" (function),  "b" (ebx), "c"(ecx), "d"(edx), "S"(esi), "D"(edi));

    return retv;
}

#endif

