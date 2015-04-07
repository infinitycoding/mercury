#ifndef UNIVERSE_H
#define UNIVERSE_H

/*
     Copyright 2012-2014 Infinitycoding all rights reserved
     This file is part of the mercury c-library.
 
     The mercury c-library is free software: you can redistribute it and/or modify
     it under the terms of the GNU Lesser General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     any later version.
 
     The mercury c-library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU Lesser General Public License for more details.
 
     You should have received a copy of the GNU Lesser General Public License
     along with the mercury c-library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <features.h>
#include <stdint.h>
#include <stdarg.h>
#include <sys/types.h>

__BEGIN_DECLS


//Universe Syscalls
#define SYS_THREAD_EXIT 0
#define SYS_THREAD_LAUNCH 1
#define SYS_ALLOC_MEMORY 2
#define SYS_IDENTIFY_UNIVERSE 3
#define SYS_PIPE_TRIGGER 4
#define USYS_CONNECT 5
#define USYS_READPORT 6
#define USYS_ACCEPT 7
#define USYS_DENY 8
#define USYS_NAME2PID 9

static inline uint32_t universe_syscall(uint32_t function, uint32_t ebx, uint32_t ecx, uint32_t edx, uint32_t esi, uint32_t edi)
{
    uint32_t retv = 0;
    asm volatile(
        "push %ebx;"
        "push %esi;"
        "push %edi"
    );

    asm volatile(
        "int $112;"
        "pop %%edi;"
        "pop %%esi;"
        "pop %%ebx;"
        : "=a" (retv) : "a" (function),  "b" (ebx), "c"(ecx), "d"(edx), "S"(esi), "D"(edi));

    return retv;
}

uint32_t linux_syscall(uint32_t function, uint32_t ebx, uint32_t ecx, uint32_t edx, uint32_t esi, uint32_t edi);
uint32_t universe_syscall(uint32_t function, uint32_t ebx, uint32_t ecx, uint32_t edx, uint32_t esi, uint32_t edi);
uint32_t fork();
uint32_t execve(const char *filename, char **argv, char **envp);
uint32_t alloc_memory(int pages);
void thread_exit(int retv);
uint32_t identify_universe(void);
#define UNIVERSE_OS ('u' | ('n' << 8) | ('i' << 16))
void thread_launch(void * function);
void thread_launchv(void * function, char **argv);
void thread_launchve(void * function, char **argv, char **envp);

int open_port(char *port);
int close_port(char *port);
int uconnect(pid_t pid, char *port);
int uread_port(char *port);
int uaccept(int req_id);

int shmget(int key, int size, int flag);
void *shmat(int shm_id, const void *adresse, int flag);

__END_DECLS

#endif

