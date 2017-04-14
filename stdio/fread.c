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
 *  @file stdio/fread.c
 *  @todo store errorcodes
 *  @author Michael Sippel <micha@infinitycoding.de>
 */

#include <unistd.h>
#include <stdio.h>

/**
 *  @brief Reads n elements wit size lengh from file.
 *  @param buf  buffer to write the elements in
 *  @param size site of one element
 *  @param n    number of elements
 *  @param file habdle of the file to be read
 *  @return total number of read elements
 */
size_t fread(void *buf, size_t size, size_t n, FILE *file)
{
    int r = read(file->handle, buf, size * n);
    if(r > 0)
        file->fpos += r;
    else
        r = 0;
    return r/size;
}
