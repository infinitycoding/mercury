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
 *  @file stdio/fclose.c
 *  @author Michael Sippel <micha@infinitycoding.de>
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


/**
 *  @brief Closes a open file.
 *  @param file The handle of the file to be closed.
 *  @return Success = 0, Failure = EOF (-1)
 */
int fclose(FILE *file)
{
    int r = close(file->handle);
    free(file);
    return r;
}