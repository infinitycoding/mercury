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
 *  @file string/strrchr.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


/**
 * @breif Searches for last occurrence of char c in str.
 * @param str string to be scanned
 * @param c searched character
 * @return pointer to the last similar char
 * NULL=no char in str is similar to c
 */
char *strrchr(const char *str, int c)
{
    int i = 0;
    char* ret = NULL;
    while (str[i] != 0)
    {
        if (str[i] == (char)c)
        {
            ret = (char*)(str+i);
        }
        i++;
    }
    return ret;
}
