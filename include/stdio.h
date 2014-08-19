#ifndef _stdio_h_
#define _stdio_h_

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

#include <features.h>
#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>


__BEGIN_DECLS

#define stdin 0
#define stdout 1
#define stderr 2

#define STDIN 0
#define STDOUT 1
#define STDERR 2
     
#define EOF -1
#define eof -1



// files
typedef struct file
{
    char *fpos;
    void *base;
    uint8_t handle;
    int8_t flags;
    int8_t unget;
    unsigned long alloc;
    uint8_t buffincrement;
} file_t;
typedef struct file FILE;


int rename(const char *oldname, const char *newname);


// printf
int printf(const char *fmt, ...);
int sprintf(char *buf, const char *fmt, ...);
int vsprintf(char *buf, const char *fmt, va_list args);
int getchar(void);

FILE *fopen(const char *path, char *modus);
int fclose(FILE *file);
size_t fread(void *buf, size_t size, size_t n, FILE *file);
size_t fwrite(void *buf, size_t size, size_t n, FILE *file);
void fseek(FILE *file,long int off, int whence);
long int ftell(FILE *file);
int fstat(int fildes, struct stat *buf);
int fflush ( FILE *stream);
int fgetc(FILE *stream);
char * fgets(char *str, int num, FILE *stream);
int fputc(int character, FILE * stream);
int fputs(const char * str, FILE * stream);

__END_DECLS

#endif

