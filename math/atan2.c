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
 *  @file math/atan2.c
 *  @author Peter Hösch <peter.hoesch@infinitycoding.de>
 */

#include <math.h>

/**
 * @brief Compute arc tangent with two parameters
 * @param y
 * @param x
 * @return atan2(y, x)
 */
double atan2(double y, double x)
{
	if(x > 0)
		return atan(y/x);
	else if(x < 0 && y >= 0)
		return atan((y / x) + M_PIl);
	else if(x < 0 && y < 0)
		return atan((y / x) - M_PIl);
	else if(x == 0 && y > 0)
		return M_PI_2l;
	else if(x == 0 && y < 0)
		return -M_PI_2l;
	else
		return 0;
}
