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
 *  @file math/asin.c
 *  @author Peter Hösch <peter.hoesch@infinitycoding.de>
 */

#include <math.h>

/**
 * @brief Calculates the arcsine of x using the taylor series
 * @param x
 * @return asin(x)
 */
double asin(double x)
{
    double sigma = 0;
    int i, j;
    for (i = 0; i < MATH_PRECISION; i++)
    {
        double tmp = 1;
        for(j = i; j > 0; j--)
            tmp *= ((double)(i+j) / (double)j);
        sigma += (tmp) * ((powi(x, 2 * i + 1)) / (powi(4, i) * (2 * i + 1)));
    }
    return sigma;
}