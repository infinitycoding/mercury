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
     along with the <name>-library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
	@author Michael Sippel (Universe Team) <micha@infinitycoding.de>
*/
#include <universe.h>
#include <stdlib.h>

int atoi(const char *nptr) {
	int num = 0;

	while(*nptr) {
		num *= 10;
		num += *nptr++ - '0';
	}

	return num;
}

long atol(const char *nptr) {
	long num = 0;

	while(*nptr) {
		num *= 10;
		num += *nptr++ - '0';
	}

	return num;
}

long long atoll(const char *nptr) {
	long long num = 0;

	while(*nptr) {
		num *= 10;
		num += *nptr++ - '0';
	}

	return num;
}

