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

size_t strnlen(const char *s, size_t maxlen);
size_t strlen(const char*);
char* strcpy(char*,const char*);
char* strncpy(char*,const char*,size_t);
char* strcat(char*,const char*);
char* strncat(char*,const char*,size_t);
int strcmp(const char*,const char*);
int strncmp(const char*,const char*,size_t);
char* strchr(const char*,int);
char* strrchr(const char*,int);

size_t strspn(const char*,const char*);
size_t strcspn(const char*,const char*);
char* strpbrk(const char*,const char*);
char* strstr(const char*,const char*);

//extern char* strerror(size_t);

extern char* strtok(char*,const char*);

extern void* memcpy(void*,const void*,size_t);
extern void* memmove(void*,const void*,size_t);
extern int memcmp(const void*,const void*,size_t);
extern void* memchr(const void*,int,size_t);
extern void* memset(void*,int,size_t);

extern void strev(char* output,char* input);
extern void itodez(int zahl,char* output);
extern void uitodez(uint32_t zahl,char* output);
extern void itohex(int zahl,char* output);
extern void uitohex(uint32_t zahl,char* output);

#endif
