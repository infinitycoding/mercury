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
 *  @file string/strncpy.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


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
    int eos = 0;
    for (i = 0; i < n; i++)
    {
        if (eos == 0)
        {
            if (src[i] == '\0')
            {
                eos = 1;
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