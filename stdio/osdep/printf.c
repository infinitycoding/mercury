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

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int puts(const char *str)
{
    int ret = write(1, str, strlen(str));
    write(1, "\n", 1);
    return ret;
}

/**
 * @brief prints a formatted string to the standard output
 * @param fmt formatted string
 * @return number of printed characters
 */
int printf(const char *fmt, ...)
{
    int size;
    char buffer[1024]; //dynamic allocation!?
    memset(buffer, 0, 1024); //Tom! Make it gemeric!

    va_list args;
    va_start(args, fmt);

    size = vsprintf(buffer, fmt, args);

    write(1,buffer,strlen(buffer)); //fixme: change numbers after setting up udrcp stuff

    va_end(args);
    return size;
}
