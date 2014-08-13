#ifndef	_string_h_
#define	_string_h_

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
#include <stdint.h>
#include <stddef.h>

// Copy
void *memcpy(void *destination, const void *source, size_t size);
void *memmove(void *destination, const void *source, size_t num);
void *memset(void *mem, int c, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// Concatenation
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

// Comparison
int memcmp(const void *mem0, const void *mem1, size_t n);
int strncmp(const char *str0, const char *str1, size_t n);

// Searching
void *memchr(const void *mem, int c, size_t n);
char *strchr(const char *str, int c);
char *strrchr(const char *str, int c);
size_t strspn(const char * str1, const char * str2);
size_t strcspn(const char *str1, const char *str2);
char *strpbrk(const char  *str1, const char *str2);
char *strstr(const char *str1, const char *str2);
char *strtok(char *string, const char *delimiters);

// Length
size_t strnlen(const char *s, size_t maxlen);
size_t strlen(const char *);

//char *strerror(size_t);

// convert integers to string
void strev(char *output, char *input);
void itodez(int zahl, char *output);
void uitodez(uint32_t zahl, char *output);
void itohex(int zahl, char *output);
void uitohex(uint32_t zahl, char *output);

#endif

