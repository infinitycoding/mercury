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
	@author Tom Slawik <tom.slawik@gmail.com>
*/

#include <atoi.h>
#include <math.h>
#include <ctype.h>
/*
	TODO: Make it compatible with both unsigned int and signed int
	TODO: implement 64-bit values
	TODO: Implement floating point values
*/

/**
 *  @brief makes string from number
 *  @param value 	Input Number
 *  @param str 	Output Buffer
 *  @param base 	Number base (e.g. 2, 8, 10, 16)
 *  @param flags 	SMALL: hexadecimal chars no caps, LEFT: number left aligned, ZEROPAD: Fill with zeroes, PLUS: + sign if positive, SPECIAL: 0x (hex)
 *  @param width 	Field width
 *  @return pointer to buffer
 */

char * itoa_ex(int value, char * str, int base, int flags, int width)
{
    char *result = str;
    unsigned int size;
    unsigned int len = 0;
    unsigned int temp = 0;
    int negative = 0;

    const char *digits = "0123456789ABCDEF";

    if (flags & SMALL)
    {
        digits = "0123456789abcdef";
    }

    if (value < 0)
    {
        value = - value;
        ++negative;
    }

    temp = value;
    do
    {
        temp /= base;
        ++len;
    }
    while (temp);
    size = len;

    if (!(flags & LEFT) && !(flags & ZEROPAD))
        while (size < width--)
            *str++ = ' ';

    if (negative)
    {
        *str++ = '-';
    }
    else if (flags & PLUS)
    {
        *str++ = '+';
    }
    if (flags & SPECIAL)
    {
        *str++ = '0';
        *str++ = 'x';
        width -= 2;
    }

    if (!(flags & LEFT) && (flags & ZEROPAD))
        while (size < width--)
            *str++ = '0';

    do
    {
        int power = powi(base, --len);
        int digit = value / power;

        *str++ = digits[digit];

        value -= digit * power;
    }
    while (len > 0);

    while (size < width--)
        *str++ = ' ';

    *str++ = '\0';

    return result;
}
