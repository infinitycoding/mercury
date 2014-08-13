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
#include <stddef.h>
#include <stdbool.h>
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

