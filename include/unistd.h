#ifndef _unistd_h_
#define _unistd_h_

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
	@author Michael Sippel <micha@infinitycoding.de>
*/
#include <features.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>

__BEGIN_DECLS



#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#define R_OK 0x1
#define W_OK 0x2
#define X_OK 0x4
#define F_OK 0x8

#define SEEK_SET 0x1
#define SEEK_CUR 0x2
#define SEEK_END 0x3

#define O_RDONLY 0x01 /* read only */
#define O_WRONLY 0x02 /* write only */
#define O_RDWR 0x04 /* read and write */
#define O_APPEND 0x08 /* append at end of file */
#define O_TRUNC 0x10 /* clear the file */
#define O_CREAT 0x20 /* create the file */
#define O_EXCL 0x40 /* forced file creation. if it already exist: fail */

typedef struct dirent
{
    int id;
    char name[256];
    struct stat stat;
} dirent_t;

int open(const char *path, int file_access, int filemode);
int close(int fd);
int read(int fd, void *buffer,size_t n);
int write(int fd,const void *buffer, size_t n);
int lseek(int fd, int off, int whence);
dirent_t *readdir(int fd, dirent_t *dir);
int chdir(const char *path);
char *getcwd(char *buf, int buflen);
int access(const char *path, int mode);

int mknod(char *path, int mode, int dev);
int mkfifo(char *path, int mode);

pid_t getpid(void);
pid_t fork(void);
int pipe(int filedes[2]);

void *sbrk(intptr_t incr);

__END_DECLS

#endif
