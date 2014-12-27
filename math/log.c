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
 *  @file math/log.c
 *  @author Adrian Jablonski <support@quadsoft.org>
 */

#include <math.h>

/**
 * @brief Calculates the natural logarythm
 */
double log(double y)
{
    double x = (y - 1) / (y + 1);
    double sigma = 0;
    int i;
    for (i = 0; i < 150; i++)
        sigma += powi(x, 2*i+1) /(2*i+1);
    return 2*sigma;
}