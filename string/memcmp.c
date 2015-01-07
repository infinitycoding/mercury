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
 *  @file string/memcmp.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


/**
* @brief Compares two memory areas.
* @param mem0 first area
* @param mem1 second area
* @param n area size
* @return = 0 areas are similar
*  > 0 the value of the first different byte of area0 is bigger
*  < 0 the value of the first different byte of area1 is bigger
*/
int memcmp(const void *mem0, const void *mem1, size_t n)
{
    const char *st0 = mem0;
    const char *st1 = mem1;
    size_t i;
    for (i = 0; st0[i] == st1[i] && i < n-1; i++);
    return st0[i] - st1[i];
}