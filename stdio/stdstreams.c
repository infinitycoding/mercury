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
 * @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 */

#include <stdio.h>
#include <unistd.h>

FILE __stdin =
{
    .fpos           = 0,
    .base           = NULL,
    .handle         = 0,
    .flags          = 0,
    .unget          = 0,
    .alloc          = 0,
    .buffincrement  = 0
};

FILE __stdout =
{
    .fpos           = 0,
    .base           = NULL,
    .handle         = 1,
    .flags          = 0,
    .unget          = 0,
    .alloc          = 0,
    .buffincrement  = 0
};


FILE __stderr =
{
    .fpos           = 0,
    .base           = NULL,
    .handle         = 2,
    .flags          = 0,
    .unget          = 0,
    .alloc          = 0,
    .buffincrement  = 0
};