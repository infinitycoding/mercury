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
 *  @file math/tanh.c
 *  @author Simon Diepold aka. tdotu <simon.diepold@Infinitycoding.de>
 */

#include <math.h>

/**
 * @brief calculates the hypobolic tangent of x
 * @param x
 * @return tanh(x)
 */
double tanh (double x)
{
    double  y = exp (x + x);
    return (y - 1.) / (y + 1.);
}
