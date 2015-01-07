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
 *  @file string/memchr.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


/**
 * @brief Searches first occurrence of c in mem.
 * @param mem Pointer to block of memory where the search is performed.
 * @param c Serched value. The function will use a unsigned char conversion of this value.
 * @param n Size of mem.
 * @return Pointer to the fist similar value
 *  or NULL if no value in mem is similar to c.
 */
void *memchr(const void *mem, int c, size_t n)
{
    size_t i;
    const unsigned char *str = mem;
    const unsigned char value = (unsigned char) c;
    for (i = 0; str[i] != value && i < n-1; i++);

    if (str[i] == value)
    {
        return (void*) (str+i);
    }
    else
    {
        return NULL;
    }
}