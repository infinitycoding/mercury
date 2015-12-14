#ifndef	_stddef_h_
#define	_stddef_h_

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
	@author Michael Sippel <micha@infinitycoding.de>
	@author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
*/


#ifndef NULL
#define NULL ((void *)0)
#endif

#define offsetof(type, member) ( (size_t) &((type*)0)->member )

typedef __SIZE_TYPE__ size_t;
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#if __cplusplus >= 201103L
typedef decltype(nullptr) nullptr_t;
#endif
#if __cplusplus >= 201103L || __STDC_VERSION__ >= 201112L
typedef long double max_align_t; // TODO depends on platform
#endif


#endif
