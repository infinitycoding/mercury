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
 *  @file math/sin.c
 *  @author Adrian Jablonski <support@quadsoft.org>
 */

#include <math.h>

/**
 * @brief Calculates sine of x
 * @param x
 * @return sin(x)
 */
double sin(double x)
{
    double sigma = 0;
    int i;
    for (i = 0; i < MATH_PRECISION; i++)
        sigma += ((powi(-1, i) * powi(x, 2 * i + 1)) / factorial(2 * i + 1));
    return sigma;
}
