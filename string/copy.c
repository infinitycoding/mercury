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
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

/**
 * @breif Copies src string to dest.
 * @param dest destination pointer
 * @param src source string
 * @return destination string pointer
 */
char *strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}

/**
 * @breif Copies n chars from src to dest untill *src == 0.
 * @param destination string
 * @param source string
 * @param maximal number of chars
 * @return destination string
 */
char *strncpy(char *dest, const char *src, size_t n)
{
    size_t i;
    bool eos = false;
    for (i = 0; i < n; i++)
    {
        if (!eos)
        {
            if (src[i] == '\0')
            {
                eos = true;
            }
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '\0';
        }

    }
    return dest;
}

/**
 * @brief Copies memory from source to destination.
 * @param destination destination string
 * @param source source string
 * @param size size of source area
 * @return pointer to destination area
 */
void *memcpy(void *destination, const void *source, size_t size)
{
    uint8_t *dest = destination;
    const uint8_t *sour = source;
    size_t i;
    for (i = 0; i < size; i++)
    {
        dest[i] = sour[i];
    }
    return destination;
}

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

