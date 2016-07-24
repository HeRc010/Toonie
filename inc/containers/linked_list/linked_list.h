#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

// std
#include "stdlib.h"
#include "stdio.h" // TODO: Remove; used for testing

typedef struct linked_list_node_t {
  int data; // TODO: Replace with generic type
} linked_list_node_t;

typedef struct linked_list_t {
  size_t size;
  linked_list_node_t *head_node;
} linked_list_t;

void linked_list_init(linked_list_t *list);

void linked_list_free(linked_list_t *list);

#endif // __LINKED_LIST_H__
