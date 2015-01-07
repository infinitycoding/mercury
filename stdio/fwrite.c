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
 *  @file stdio/fwrite.c
 *  @author Michael Sippel <micha@infinitycoding.de>
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @todo: store errorcodes
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


/**
 *  @brief Writes n elements with size lengh into a file at it's filehandle position.
 *  @param buf  source element buffer
 *  @param size size of one element
 *  @param n    number of elements to be written
 *  @param file destination file
 *  @return number of written elements.
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
        return r/size;
    }

    return 0;
}