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


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


//default file handles
FILE __stdin = {.handle=0, .fpos=0, .base=0, .flags=0, .unget=0, .alloc=0, .buffincrement=0};
FILE __stdout = {.handle=1, .fpos=0, .base=0, .flags=0, .unget=0, .alloc=0, .buffincrement=0};
FILE __stderr = {.handle=2, .fpos=0, .base=0, .flags=0, .unget=0, .alloc=0, .buffincrement=0};

/**
 *  @file stdio/fopen.c
 *  @author Michael Sippel <micha@infinitycoding.de>
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 */

/**
 *  @brief Opens a file in a specific mode and returns a file handle.
 *  @param path   the filname including path to the file to be opend.
 *  @param modus  the mode in which the file shoud be open. Read ("r"), write ("w") or append("a"), update/read ("r+"), update/write("w+") and update/append ("a+")
 *  @return Succes = FILE pointer, Failure = NULL
 */
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

        if((m |= O_APPEND))
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
