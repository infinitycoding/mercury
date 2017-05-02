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
 *  @file stdio/fputc.c
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 */

#include <unistd.h>
#include <stdio.h>

/**
 *  @brief Writes a character to a stream.
 *  @param character the character to be written
 *  @param stream
 *  @return Success = the input character, Failure = EOF
 */
int fputc(int character, FILE * stream)
{
    if(write(stream->handle, &character, 1))
        return character;
    else
        return EOF;
}
