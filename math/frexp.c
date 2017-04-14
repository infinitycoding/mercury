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
 *  @file math/log10.c
 *  @author Simon Diepold aka. tdotu <simon.diepold@infinitycoding.de>
 */

#include <math.h>

/**
 * @brief x=significand*2^exp
 * @param x
 * @param exp pointer to the exponent destination
 * @return significand
 */
double frexp (double x, int* exp)
{
    int sign = 1;
    if(x < 0)
    {
        sign = -1;
        x *= sign;
    }
    else if(x == 0.0)
    {
        *exp = 0;
        return 0.0;
    }

    *exp = 0;
    int e = 1;
    double sig = x;
    while(sig < 0.5  || sig >= 1.0)
    {
        e *= 2;
        (*exp)++;
        sig = x/e;
    }
    return sig*sign;
}
