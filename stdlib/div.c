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
     along with the <name>-library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
	@author Michael Sippel (Universe Team) <micha@infinitycoding.de>
*/
#include <universe.h>
#include <stdlib.h>

div_t div(int numer, int denom)
{
    div_t rc;
    rc.quot = numer / denom;
    rc.rem  = numer % denom;

    return rc;
}

ldiv_t ldiv(long int numer, long int denom)
{
    ldiv_t rc;
    rc.quot = numer / denom;
    rc.rem  = numer % denom;

    return rc;
}

lldiv_t lldiv(long long int numer, long long int denom)
{
    lldiv_t rc;
    rc.quot = numer / denom;
    rc.rem  = numer % denom;

    return rc;
}

