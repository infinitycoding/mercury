#ifndef	_limits_h_
#define	_limits_h_

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


// Chars
#define CHAR_BIT 	8

#define SCHAR_MIN 	-128
#define SCHAR_MAX 	127
#define UCHAR_MAX 	255
#define CHAR_MIN 	UCHAR_MIN
#define CHAR_MAX 	UCHAR_MAX

#define INT8_MIN	SCHAR_MIN
#define INT8_MAX  	SCHAR_MAX
#define UINT8_MAX 	UCHAR_MAX

// shorts
#define SHRT_MAX	32767
#define SHRT_MIN	-32768
#define USHRT_MAX	65535

#define INT16_MIN	SHRT_MIN
#define INT16_MAX	SHRT_MAX
#define UINT16_MAX	USHRT_MAX


//ints
#define INT_MIN		-2147483648
#define INT_MAX		2147483647
#define UINT_MAX	0xFFFFFFFF

#define INT32_MIN 	INT_MIN
#define INT32_MAX 	INT_MAX
#define UINT32_MAX 	UINT_MAX

#define LONG_MIN	INT_MIN
#define LONG_MAX	INT_MAX
#define ULONG_MAX	UINT_MAX

//long longs
#define LLONG_MIN	((int64_t) -0x8000000000000000LL)
#define LLONG_MAX	0x7FFFFFFFFFFFFFFFLL
#define ULLONG_MAX	((uint64_t) -1ULL)

#define INT64_MIN	LLONG_MIN
#define INT64_MAX	LLONG_MAX
#define UINT64_MAX	ULLONG_MAX


#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX
#define UINTPTR_MAX UINT32_MAX

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX
#define UINTMAX_MAX UINT64_MAX

#endif