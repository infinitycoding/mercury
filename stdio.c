/*
     Copyright 2012-2014 Infinitycoding all rights reserved
     This file is part of the mercury c library.
 
     The mercury c library is free software: you can redistribute it and/or modify
     it under the terms of the GNU Lesser General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     any later version.
 
     The mercury c library is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU Lesser General Public License for more details.
 
     You should have received a copy of the GNU Lesser General Public License
     along with the mercury c library.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 *  @author Michael Sippel <micha@infinitycoding.de>
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 */


#include <universe.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

/**
 * @brief Renames a file.
 * @param oldname The old name of the file
 * @param newname The new name for the file
 * @return 0 if the operation was successful
 */
int rename(const char *oldname, const char *newname)
{
    return linux_syscall(SYS_RENAME,(uint32_t) oldname,(uint32_t) newname, 0, 0, 0);
}



FILE *fopen(const char *path, char *modus)
{
    FILE *file = malloc(sizeof(FILE));

    int m = 0;
    if(strchr(modus, 'r'))
    {
        m = O_RDONLY;
    }
    if(strchr(modus, 'w'))
    {
        if(m == O_RDONLY)
        {
            m = O_RDWR;
        }
        else
        {
            m = O_WRONLY;
        }
        m |= O_CREAT;
    }

    if(strchr(modus, 'a'))
    {
        m |= O_APPEND;
    }
    if(strchr(modus, '+'))
    {
        m |= O_RDWR;
    }

    file->handle = open(path, m, 0x1ff0);
    if(! (file->handle < 0))
    {
        struct stat stat;
        fstat(file->handle, &stat);
        file->alloc = stat.st_size;

        if(m |= O_APPEND)
        {
            file->fpos = (char *)file->alloc;
        }
        else
        {
            file->fpos = 0;
        }

        return file;
    }
    else
    {
        return NULL;
    }
}

int fclose(FILE *file)
{
    close(file->handle);
    free(file);
    return 0;
}


/*
    todo: store errorcodes
*/
size_t fread(void *buf, size_t size, size_t n, FILE *file)
{
    int r = read(file->handle, buf, size * n);
    if(r > 0)
        file->fpos += r;
    else
        r = 0; 
    return r;
}


/*
    todo: store errorcodes
*/
size_t fwrite(void *buf, size_t size, size_t n, FILE *file)
{
    size_t bytes = size * n;
    int r = write(file->handle, buf, bytes);
    if(r > 0)
    {
        if((unsigned long)file->fpos > file->alloc)   //is that really correct?
        {
            file->alloc = (unsigned long) file->fpos;
        }
        return r;
    }

    return 0;
}

void fseek(FILE *file, int off, int whence)
{
    switch(whence)
    {
    case SEEK_SET: // absolute
        file->fpos = (char *)off;
        break;
    case SEEK_CUR: // relative from current position
        file->fpos += off;
        break;
    case SEEK_END: // relative from end
        file->fpos = (char*)(file->alloc - off);
        break;
    }
    lseek(file->handle, off, whence);
}

int ftell(FILE *file)
{
    return (int)file->fpos;
}

int fstat(int fildes, struct stat *buf)
{
    return linux_syscall(SYS_FSTAT, fildes, (uint32_t) buf, 0, 0, 0);
}

int fflush ( FILE *stream)
{
    return 0; // universe has currently no difference between open and written files
}

int fgetc(FILE *stream)
{
    int c = 0;
    if(read(stream->handle, &c, 1) == EOF)
        return EOF;
    else
        return c;
}

char * fgets(char *str, int num, FILE *stream)
{
    int i, c = 0;
    for(i = 0; i < num; i++)
    {
        c = fgetc(stream);
        if(c == EOF)
        {
            str[i] = 0;
            break;
        }

        if(c == '\n')
        {
            str[i] = '\n';
            str[i+1] = '0';
            break;
        }

        str[i] = (char) c;

    }

    return str;
}

int fputc(int character, FILE * stream)
{
    if(write(stream->handle, &character, 1))
        return character;
    else
        return EOF;
}


int fputs(const char * str, FILE * stream)
{
    size_t len = strlen(str);
    int r = write(stream->handle, str, len);
    if(r)
        return r;
    return EOF;
}
