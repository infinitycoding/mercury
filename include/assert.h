#ifndef _assert_h_
#define _assert_h_
/*
     Copyright 2015 Infinitycoding all rights reserved
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
 *	@author Michael Sippel (Universe Team) <micha@infinitycoding.de>
 */
#include <features.h>

#ifndef _DEBUG
#define assert(x)
#else
#define assert(x) (void)((x) || (__assert (#x, __FILE__, __LINE__),0))
#endif

__BEGIN_DECLS

void __assert (const char *msg, const char *file, int line);

__END_DECLS

#endif

