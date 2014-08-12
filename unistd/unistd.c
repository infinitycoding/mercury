/*
	Copyright 2012 universe coding group (UCG) all rights reserved
	This file is part of the Universe Kernel.

	Universe Kernel is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	Universe Kernel is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Universe Kernel.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 *@author Simon Diepold aka. tdotu <simon.diepold@infinitycoding.de>
 **/

#include <universe.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int write(int fd,const void *buffer, size_t n)
{
    int ret = (int)linux_syscall(SYS_WRITE, fd, (uint32_t)buffer, n, 0, 0);
    return ret;
}

int read(int fd, void *buffer,size_t n)
{
    int ret = (int)linux_syscall(SYS_READ, fd, (uint32_t)buffer, n, 0, 0);
    return ret;
}

int open(const char *path, int file_access, int filemode)
{
    int ret = (int)linux_syscall(SYS_OPEN, (uint32_t)path, file_access, filemode, 0, 0);
    return ret;
}

int close(int fd)
{
    int ret = (int)linux_syscall(SYS_CLOSE, fd, 0, 0, 0, 0);
    return ret;
}

dirent_t *readdir(int fd)
{
    return (dirent_t *)linux_syscall(SYS_READDIR, fd, 0, 0, 0, 0);
}

int chdir(const char *path)
{
    int ret = (int)linux_syscall(SYS_CHDIR,(uint32_t)path, 0, 0, 0, 0);
    return ret;
}

int lseek(int fd, int off, int whence)
{
    int ret = (int)linux_syscall(SYS_LSEEK, fd, off, whence, 0, 0);
    return ret;
}

int getchar(void)
{
    char c;
    read(stdin, &c, 1);
    return (int)c;
}

char *getcwd(char *buf, int buflen)
{
    if(buf == NULL && buflen != 0)
        buf = (char *)malloc(sizeof(char) * buflen);

    return (char *)linux_syscall(SYS_GETCWD,(uint32_t)buf, buflen, 0, 0, 0);
}

int mknod(char *path, int mode, int dev)
{
    int ret = (int)linux_syscall(SYS_MKNOD, (uint32_t) path, mode, dev, 0, 0);
    return ret;
}

int mkfifo(char *path, int mode)
{
    return mknod(path, S_IFIFO | S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH, 0);
}
