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
 *  @author Simon Diepold aka. Tdotu <simon.diepold@infinitycoding.de>
 *  @author Johannes Spangenberg aka. JojOatXGME <jojo@xgme.de>
 */

#include <stdint.h>
#include <string.h>


/**
 * @brief Returns the string lengh <= maxlen.
 * @param s the string
 * @param maxlen the maximal lengh
 * @return string lengh<= maxlen
 */
size_t strnlen(const char *s, size_t maxlen)
{
    const char *str = s;
    while (*str && maxlen)
    {
        ++str;
        maxlen--;
    }

    return str - s;
}


/**
 * @breif Returns the string lengh.
 * @param string pointer
 * @return string lengh
 */
size_t strlen(const char *string)
{
    size_t i = 0;
    while (string[i])
    {
        i++;
    }

    return i;
}


/**
 * @breif Copies src string to dest.
 * @param dest destination pointer
 * @param src source string
 * @return destination string pointer
 */
char *strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return dest;
}


/**
 * @breif Copies n chars from src to dest untill *src == 0.
 * @param destination string
 * @param source string
 * @param maximal number of chars
 * @return destination string
 */
char *strncpy(char *dest, const char *src,size_t n)
{
    size_t i;
    bool eos = false;
    for (i = 0; i < n; i++)
    {
        if (!eos)
        {
            if (src[i] == '\0')
            {
                eos = true;
            }
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '\0';
        }

    }
    return dest;
}


/**
 * @brief Copies src string behind dest string.
 * @param dest destination string
 * @param src source string
 * @return destination string
 */
char *strcat(char *dest, const char *src)
{
    size_t n = strlen(dest);
    strcpy((char*)(dest+n),src);
    return dest;
}


/**
 * @breif Copies n chars from src behind dest string untill *src=0.
 * @param dest destination string
 * @param src source string
 * @param n maximal number of chars
 * @return destination string
 */
char *strncat(char *dest, const char *src, size_t n)
{
    size_t i = strlen(dest);
    strncpy((char*)(dest+i),src,n);
    return dest;
}


/**
 * @breif Compares two strings.
 * @param str0 string to be compared
 * @param str1 string to be compared
 * @return = 0 strings are similar
 *  > 0 value of the first different char of string0 is bigger
 *  < 0 value of the first different char of string1 is bigger
 */
int strcmp(const char *str0, const char *str1)
{
    size_t i;
    for (i = 0; str0[i] == str1[i] && str0[i] != 0; i++);
    int ret = str0[i] - str1[i];
    return ret;
}


/**
 * @breif Compares n chars of two string untill the value of str0 and str1 is not zero.
 * @param str0 string to be compared
 * @param str1 string to be compared
 * @param numer of chars
 * @return = 0 strings are similar
 *  > 0 value of the first different char of string0 is bigger
 *  < 0 value of the first different char of string1 is bigger
 */
int strncmp(const char *str0, const char *str1, size_t n)
{
    uint32_t i;
    int ret = 0;

    for (i = 0; str0[i] == str1[i] && str0[i] != 0 && i < n-1; i++);
    ret = str0[i] - str1[i];
    return ret;
}


/**
 * @breif Searches char c in str.
 * @param str string
 * @param c searched character
 * @return pointer to the first similar char
 * NULL=no char in str is similar to c
 */
char *strchr(const char *str, int c)
{
    int i = 0;
    while (str[i] != (char)c && str[i] != 0)
    {
        i++;
    }
    if (str[i])
    {
        return (char*)(str+i);
    }
    return NULL;
}


/**
 * @breif Searches for last occurrence of char c in str.
 * @param str string to be scanned
 * @param c searched character
 * @return pointer to the last similar char
 * NULL=no char in str is similar to c
 */
char *strrchr(const char *str, int c)
{
    int i = 0;
    char* ret = NULL;
    while (str[i] != 0)
    {
        if (str[i] == (char)c)
        {
            ret = (char*)(str+i);
        }
        i++;
    }
    return ret;
}


/**
 * @breif Returns the position of the first occurrence of any character from str2 in str1. (except '\0')
 * @param str1 string to be scanned
 * @param str2 searched characters
 * @return The position of the first occurrence in str1 or 0 if there is no occurence.
 */
size_t strcspn(const char *str1, const char *str2)
{
    size_t position = 0;
    const char *p2;
    while(str1[position])
    {
        p2 = str2;
        while(*p2)
        {
            if(str1[position] == *p2++)
                return position;
        }

        position++;
    }
    return 0;
}


/**
 * @breif Returns a pointer to the first occurrence of any character from str2 in str1. (except '\0')
 * @param str1 string to be scanned
 * @param str2 searched characters
 * @return Pointer to the first occurrence in str1 or a NULL pointer if there is no occurrence.
 */
char *strpbrk(const char  *str1, const char *str2)
{
    const char *p2;
    while(*str1)
    {
        p2 = str2;
        while(*p2)
        {
            if(*str1 == *p2++)
                return (char *)str1;
        }
        ++str1;
    }
    return NULL;
}


/**
 * @brief Returns a pointer to the first occurrence of str2 in str1.
 * @param str1 string to be scanned
 * @param str2 string to be found in str1
 * @return Pointer to the first occurrence in str1 or a NULL pointer if there is no occurrence.
 */
char *strstr(const char *str1, const char *str2)
{
    const char * p1 = str1;
    const char * p2;
    while ( *str1 )
    {
        p2 = str2;
        while ( *p2 && ( *p1 == *p2 ) )
        {
            ++p1;
            ++p2;
        }
        if ( ! *p2 )
        {
            return (char *) str1;
        }
        ++str1;
        p1 = str1;
    }
    return NULL;
}


/**
 * @brief Returns the lengh of the initial segment of str1 which consists only of the charactes given in str2.
 * @param str1 string to be scanned
 * @param str2 containing the characters to match
 * @return the lengh of the initial segment
 */
size_t strspn(const char * str1, const char * str2)
{
    size_t len = 0;
    const char * p;
    while ( str1[ len ] )
    {
        p = str2;
        while ( *p )
        {
            if ( str1[len] == *p )
            {
                break;
            }
            ++p;
        }
        if ( ! *p )
        {
            return len;
        }
        ++len;
    }
    return len;
}


char *strtok(char *string, const char *delimiters)
{
    static char *str = NULL;

    if (string != NULL)
    {
        str = string;
    }
    if (str == NULL)
    {
        return NULL;
    }

    size_t i;
    for (i = 0; str[i] != '\0'; i++)
    {
        const char *deli;
        for(deli = delimiters; *deli != '\0'; deli++)
        {
            if(str[i] == *deli)
            {
                char *ret = str;
                str[i] = '\0';
                str = str + i + 1;
                return ret;
            }
        }
    }

    char *ret = str;
    str = NULL;
    return ret;
}


/**
 * @brief Copies memory from source to destination.
 * @param destination destination string
 * @param source source string
 * @param size size of source area
 * @return pointer to destination area
 */
void *memcpy(void *destination, const void *source, size_t size)
{
    uint8_t *dest = destination;
    const uint8_t *sour = source;
    size_t i;
    for (i = 0; i < size; i++)
    {
        dest[i] = sour[i];
    }
    return destination;
}


/**
 * @brief Moves memory from source to destination area.
 *
 * Unlike memcpy, the overlapping of source and destination is allowed.
 *
 * @param destination destination area
 * @param source source area
 * @param num number of bytes to copy
 * @return pointer to destination area
 */
void *memmove(void *destination, const void *source, size_t num)
{
    uint8_t *dest = destination;
    const uint8_t *src = source;
    if (dest > src && src + num > dest && num != 0)
    {
        size_t i = num;
        do
        {
            i--;
            dest[i] = src[i];
        }
        while (i != 0);
    }
    else
    {
        // because we know that memcpy copy bytes from left to right.
        memcpy(dest, src, num);
    }
    return destination;
}


/**
 * @brief Compares two memory areas.
 * @param mem0 first area
 * @param mem1 second area
 * @param n area size
 * @return = 0 areas are similar
 *  > 0 the value of the first different byte of area0 is bigger
 *  < 0 the value of the first different byte of area1 is bigger
 */
int memcmp(const void *mem0, const void *mem1, size_t n)
{
    const char *st0 = mem0;
    const char *st1 = mem1;
    size_t i;
    for (i = 0; st0[i] == st1[i] && i < n-1; i++);
    return st0[i] - st1[i];
}


/**
 * @brief Searches first occurrence of c in mem.
 * @param mem Pointer to block of memory where the search is performed.
 * @param c Serched value. The function will use a unsigned char conversion of this value.
 * @param n Size of mem.
 * @return Pointer to the fist similar value
 *  or NULL if no value in mem is similar to c.
 */
void *memchr(const void *mem, int c, size_t n)
{
    size_t i;
    const unsigned char *str = mem;
    const unsigned char value = (unsigned char) c;
    for (i = 0; str[i] != value && i < n-1; i++);

    if (str[i] == value)
    {
        return (void*) (str+i);
    }
    else
    {
        return NULL;
    }
}


/**
 * @brief Fill mem with value c.
 * @param mem Block of memory to fill.
 * @param c Value to be set. The function will use a unsigned char conversion of this value.
 * @param n size of mem.
 * @return returns mem.
 */
void *memset(void *mem, int c, size_t n)
{
    unsigned char *str = mem;
    size_t i;
    for (i = 0; i < n; i++)
    {
        str[i] = (unsigned char) c;
    }
    return mem;
}