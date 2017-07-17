/*
     Copyright 2015 Infinitycoding all rights reserved
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

/**
 *	@author Michael Sippel (Universe Team) <micha@infinitycoding.de>
 */
#include <syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

sighandler_t signal(int signum, sighandler_t handler)
{
    linux_syscall(SYS_SIGNAL, signum,(uint32_t) handler, 0, 0, 0);
    return handler;
}

int kill(pid_t pid, int sig)
{
    return linux_syscall(SYS_KILL, pid, sig, 0, 0, 0);
}

int raise(int sig)
{
    return kill(getpid(), sig);
}
