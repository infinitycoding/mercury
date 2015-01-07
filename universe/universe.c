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

#include <universe.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

uint32_t fork()
{
    uint32_t pid;
    asm volatile("int $128;": "=a"(pid) : "a" (SYS_FORK));
    return pid;
}

uint32_t execve(const char *filename, char **argv, char **envp)
{
    uint32_t ret;
    asm volatile("int $128;": "=a"(ret) : "a" (SYS_EXECVE), "b" (filename), "c" (argv), "d" (envp));
    return ret;
}

// universe stuff

void thread_exit(int retv)
{
    asm volatile("int $112;": : "a" (SYS_THREAD_EXIT) , "b"(retv));
}

extern char** environ;

void thread_launch(void * function)
{
    asm volatile("pushl %%ebx; int $112; popl %%ebx;": : "a"(SYS_THREAD_LAUNCH) , "b"(function), "c" (0), "d"(environ),"S" (&thread_exit));
}

void thread_launchv(void * function, char **argv)
{
    asm volatile("pushl %%ebx; int $112; popl %%ebx;": : "a"(SYS_THREAD_LAUNCH) , "b"(function), "c" (argv), "d"(environ),"S" (&thread_exit));
}
void thread_launchve(void * function, char **argv, char **envp)
{
    asm volatile("pushl %%ebx; int $112; popl %%ebx;": : "a"(SYS_THREAD_LAUNCH) , "b"(function), "c" (argv), "d"(envp),"S" (&thread_exit));
}

uint32_t alloc_memory(int pages)
{
    uint32_t addr;
    asm volatile("int $112;" : "=a" (addr) : "a" (SYS_ALLOC_MEMORY), "b" (pages));
    return addr;
}

uint32_t identify_universe(void)
{
    return universe_syscall(SYS_IDENTIFY_UNIVERSE,0,0,0,0,0);
}


// socket port stuff TODO:extra files!!
static char pstr[32];
char *port_str(int port)
{
    int pid = getpid();
	sprintf(pstr, "/proc/%d/socket/%d", pid, port);

	return &pstr;
}

int open_port(int port)
{
	return mkdir(port_str(port), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

int close_port(int port)
{
	return rmdir(port_str(port));
}

int uconnect(pid_t pid, int port)
{
	return (int)universe_syscall(USYS_CONNECT,pid,port,0,0,0);
}

int uread_port(int port)
{
	return (int)universe_syscall(USYS_READPORT,port,0,0,0,0);
}

int uaccept(int req_id)
{
	return (int)universe_syscall(USYS_ACCEPT,req_id,0,0,0,0);
}


