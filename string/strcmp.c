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
 *  @file string/strcmp.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */


#include <string.h>


 /**
 * @breif Compares two strings.
 * @param str0 string to be compared
 * @param str1 string to be compared
 * @return = 0 strings are similar
 *  > 0 value of the first different char of string0 is bigger
 *  < 0 value of the first different char of string1 is bigger
 */
int strcmp(const char *str0, const char *str1)
{
    size_t i;
    for (i = 0; str0[i] == str1[i] && str0[i] != 0; i++);
    int ret = str0[i] - str1[i];
    return ret;
}