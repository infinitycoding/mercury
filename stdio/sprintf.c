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
 * @author Tom Slawik <tom.slawik@gmail.com> (Kernel implementation)
 * @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de> (usermode modification)
 */

#include <stdio.h>
#include <stdarg.h>

/**
 * @brief Prints a formated string into a buffer
 * @param buf pointer to the destination buffer
 * @param fmt formatted string to be printed
 * @return number of printed characters
 */
int sprintf(char *buf, const char *fmt, ...)
{
    int size;

    va_list args;
    va_start(args, fmt);

    size = vsprintf(buf, fmt, args);

    va_end(args);
    return size;
}