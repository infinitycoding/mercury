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
 *  @file stdio/fseek.c
 *  @author Michael Sippel <micha@infinitycoding.de>
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *  @brief Sets the position of a file handle.
 *  @param file   the file handle to be set
 *  @param off    the position offset (added to whence)
 *  @param whence Startposition of the offset (SEEK_SET = offset is the absolute position in the file, SEEK_SET relativ from current position, SEEK_END relativ from end)
 */
void fseek(FILE *file, long int off, int whence)
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
