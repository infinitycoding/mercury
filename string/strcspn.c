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
 *  @file string/strcspn.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


/**
 * @breif Returns the position of the first occurrence of any character from str2 in str1. (except '\0')
 * @param str1 string to be scanned
 * @param str2 searched characters
 * @return The position of the first occurrence in str1 or 0 if there is no occurence.
 */
size_t strcspn(const char *str1, const char *str2)
{
    size_t position = 0;
    const char *p2;
    while(str1[position])
    {
        p2 = str2;
        while(*p2)
        {
            if(str1[position] == *p2++)
                return position;
        }

        position++;
    }
    return 0;
}