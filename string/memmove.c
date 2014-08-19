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
 *  @file string/memmove.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */



#include <string.h>


/**
 * @brief Moves memory from source to destination area.
 *
 * Unlike memcpy, the overlapping of source and destination is allowed.
 *
 * @param destination destination area
 * @param source source area
 * @param num number of bytes to copy
 * @return pointer to destination area
 */
void *memmove(void *destination, const void *source, size_t num)
{
    uint8_t *dest = destination;
    const uint8_t *src = source;
    if (dest > src && src + num > dest && num != 0)
    {
        size_t i = num;
        do
        {
            i--;
            dest[i] = src[i];
        }
        while (i != 0);
    }
    else
    {
        // because we know that memcpy copy bytes from left to right.
        memcpy(dest, src, num);
    }
    return destination;
}