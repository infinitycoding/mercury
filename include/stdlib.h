#ifndef _stdlib_h_
#define _stdlib_h_

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
*/

#include <limits.h>
#include <features.h>
#include <stdint.h>
#include <stddef.h>


__BEGIN_DECLS

#define NUM_PAGES(n) ((((n) + 0xfff) & 0xfffff000) / 4096)

#define EXIT_SUCCESS 0
#define EXIT_FAILURE -1

#define RAND_MAX  INT_MAX

typedef struct
{
	int quot;
	int rem;
} div_t;

typedef struct
{
	long quot;
	long rem;
} ldiv_t;

typedef struct
{
	long long quot;
	long long rem;
} lldiv_t;

int atoi(const char *nptr);
long int atol(const char *nptr);
long long int atoll(const char *nptr);

int rand(void);
void srand(unsigned int seed);

void exit(int retv);

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t num, size_t size);
void *realloc(void *ptr, size_t size);

char *getenv(const char *name);

int abs(int j);
long int labs(long int j);
long long int llabs(long long int j);

div_t div(int numer, int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);

__END_DECLS

#endif

