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
 * @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de> (usermode modification)
 */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>


/**
 * @brief prints a formatted string to stream
 * @param fmt formatted string
 * @return number of printed characters
 */
int fprintf(FILE *stream, const char *fmt, ...)
{
    int size;
    char buffer[1024]; //dynamic allocation!?
    memset(buffer, 0, 1024); //Tom! Make it gemeric! (I guess I have to do it...)

    va_list args;
    va_start(args, fmt);
    size = vsprintf(buffer, fmt, args);
    fwrite(buffer, sizeof(char), size, stream);
	va_end(args);
	return size;
}