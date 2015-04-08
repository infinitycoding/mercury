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
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//#include <universe.h>

typedef struct heap_node
{
    size_t size;

    struct heap_node *prev;
    struct heap_node *next;
} heap_node_t;

static heap_node_t *first_node = NULL;

/*
 * Insert in the list
 */
void heap_insert_node(heap_node_t *node)
{
    node->prev = NULL;
    node->next = first_node;
    if(first_node != NULL)
        first_node->prev = node;

    first_node = node;
}

/**
 * remove node from list
 */
void heap_remove_node(heap_node_t *node)
{
    if(node->prev != NULL)
        node->prev->next = node->next;

    if(node->next != NULL)
        node->next->prev = node->prev;
}

/**
 * search node with minimum size
 */
heap_node_t *heap_find_node(size_t size)
{
    heap_node_t *node = first_node;
    heap_node_t *best_node = NULL;

    while(node != NULL)
    {
        if(node->size >= size)
        {
            if(best_node == NULL || node->size < best_node->size)
                best_node = node;
        }

        node = node->next;
    }

    return best_node;
}

heap_node_t *heap_create_node(size_t size)
{
    size_t n = size + sizeof(heap_node_t);
    heap_node_t *new_node = sbrk(n) - n;
    new_node->size = size;

    return new_node;
}

void *malloc(size_t size)
{
    heap_node_t *node = heap_find_node(size);
    if(node == NULL)
        node = heap_create_node(size);
    else
        heap_remove_node(node);

    return ((void*)node + sizeof(heap_node_t));
}

void free(void *ptr)
{
    if(ptr <= 0)
        return;
    heap_node_t *node = (heap_node_t*)((uintptr_t)ptr - sizeof(heap_node_t));
    heap_insert_node(node);
}

void *calloc(size_t num, size_t size)
{
    void *data = malloc(size);
    memset(data, 0, size);

    return data;
}

void *realloc(void *ptr, size_t size)
{
    void *dest = malloc(size);
    heap_node_t *source_alloc = ptr - sizeof(heap_node_t);

    memmove(dest, ptr, source_alloc->size);
    free(ptr);

    return dest;
}


