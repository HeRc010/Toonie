#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "stdlib.h"

typedef struct linked_list_node_t {
  // ...
} linked_list_node_t;

typedef struct linked_list_t {
  size_t size;
  linked_list_node_t *head_node;
} linked_list_t;

void linked_list_init(linked_list_t *list);

void linked_list_free(linked_list_t *list);

#endif // __LINKED_LIST_H__
