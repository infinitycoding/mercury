#ifndef _features_h_
#define _features_h_

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
	@author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
	@author Michael Sippel <micha@infinitycoding.de>
	@author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
*/


#ifdef    __cplusplus
#  define __BEGIN_DECLS extern "C" {
#  define __END_DECLS   }
#else
#  define __BEGIN_DECLS
#  define __END_DECLS
#endif

#if __cplusplus >= 201103L
#  define __noexcept noexcept
#elif defined __cplusplus
#  define __noexcept throw()
#else
#  define __noexcept
#endif

#if __cplusplus >= 201103L
#  define __noreturn [[noreturn]]
#else
#  define __noreturn __attribute__((__noreturn__))
#endif

#define __pure __attribute__((__pure__))
#define __nonnull(...) __attribute__((__nonnull__(__VA_ARGS__)))

#if __cplusplus >= 201103L
#  define __nullptr nullptr
#else
#  define __nullptr 0
#endif


#endif
