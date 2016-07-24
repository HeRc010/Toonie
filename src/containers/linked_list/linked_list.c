#include "containers/linked_list/linked_list.h"

void linked_list_init(linked_list_t *list) {
  printf("Pointer before: %d\n", (int) list);

  list = malloc( sizeof(linked_list_t) );

  printf("Pointer after: %d\n", (int) list);

  // list->size = 0;
  // list->head_node = 0;
}

void linked_list_free(linked_list_t *list) {

}
