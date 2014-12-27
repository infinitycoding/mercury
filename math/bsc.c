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
 *  @file math/bsc.c
 *  @author Simon Diepold aka. tdotu <simon.diepold@infinitycoding.de>
 */

#include <math.h>

/**
 * @brief Returns the bit number of the forst set bit
 * @param i valute to can
 * @return index of the first set bit
 */
unsigned int bit_scan_forward(unsigned int i)
{
    unsigned int j;

    for (j = 0; j < 32; j++)
    {
        if (i & (1 << j))
        {
            return j;
        }
    }
    return -1;
}