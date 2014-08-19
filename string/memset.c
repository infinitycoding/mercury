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
 *  @file string/memset.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


/**
 * @brief Fill mem with value c.
 * @param mem Block of memory to fill.
 * @param c Value to be set. The function will use a unsigned char conversion of this value.
 * @param n size of mem.
 * @return returns mem.
 */
void *memset(void *mem, int c, size_t n)
{
    unsigned char *str = mem;
    size_t i;
    for (i = 0; i < n; i++)
    {
        str[i] = (unsigned char) c;
    }
    return mem;
}