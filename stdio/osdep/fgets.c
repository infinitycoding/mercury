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
 *  @file stdio/fgets.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 */

#include <stdio.h>

/**
 *  @brief Gets a "\n" terminated string from stream.
 *  @param str    pointer to a buffer for the sting
 *  @param num    the maximal number of characters to be read.
 *  @param stream the stream to be read.
 *  @return Success = the same pointer as str, Failure at first character = NULL
 */
char * fgets(char *str, int num, FILE *stream)
{
    int i, c = 0;
    for(i = 0; i < num; i++)
    {
        c = fgetc(stream);
        if(c == EOF)
        {
            if(i == 0)
                return NULL;

            str[i] = 0;
            break;
        }

        if(c == '\n')
        {
            str[i] = '\n';
            str[i+1] = '0';
            break;
        }

        str[i] = (char) c;

    }

    return str;
}
