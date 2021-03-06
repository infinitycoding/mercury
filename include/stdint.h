#ifndef	_stdint_h_
#define	_stdint_h_

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

typedef unsigned char     	uint8_t;
typedef unsigned short    	uint16_t;
typedef unsigned int      	uint32_t;
typedef unsigned long long 	uint64_t;

typedef signed char		int8_t;
typedef signed short 		int16_t;
typedef signed int 		int32_t;
typedef signed long long 	int64_t;

typedef unsigned int 		uintptr_t;
typedef long int 		intptr_t;

typedef int64_t 		intmax_t;
typedef uint64_t 		uintmax_t;

typedef unsigned int 		paddr_t;
typedef unsigned int 		vaddr_t;

#endif

