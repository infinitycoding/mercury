#ifndef _list_h_
#define _list_h_

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
 *  @author Andreas Hahn aka. thedrakor
 *  @copyright GNU Lesser Public License
 */

#include <features.h>
#include <mutex.h>

__BEGIN_DECLS

struct list_node
{
    struct list_node *next;
    struct list_node *prev;
    void *element;
};

typedef struct
{
    mutex lock;
    struct list_node *head;
} list_t;

typedef struct
{
    list_t *list;
    struct list_node *current;
} iterator_t;

list_t* list_create(void);
void    list_destroy(list_t *list);
void    list_splice(struct list_node *start, struct list_node *end, struct list_node *target);
list_t* list_push_back(list_t *list, void *element);
list_t* list_push_front(list_t *list, void *element);
void*   list_pop_back(list_t *list);
void*   list_pop_front(list_t *list);
void*   list_remove_node(struct list_node *node);
int     list_length(list_t *list);
bool    list_is_empty(list_t *list);
void    list_lock(list_t *list);
void    list_unlock(list_t *list);

iterator_t iterator_create(list_t *list);
void list_insert_after(iterator_t *it, void *element);
void list_insert_before(iterator_t *it, void *element);
void *list_get_current(iterator_t *it);
void list_next(iterator_t *it);
void list_previous(iterator_t *it);
bool list_is_last(iterator_t *it);
void list_set_first(iterator_t *it);
void *list_remove(iterator_t *it);


__END_DECLS

#endif
