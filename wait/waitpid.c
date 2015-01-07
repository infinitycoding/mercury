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

/**
 *  @file wait/waitpid.c
 *  @author Micha <micha@infinitycoding.de>
 */

#include <universe.h>
#include <sys/wait.h>
#include <sys/types.h>

pid_t waitpid(pid_t pid, int *status, int options)
{
    return (pid_t) linux_syscall(SYS_WAITPID, pid, status, options, 0, 0);
}

