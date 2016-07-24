#include "containers/linked_list/linked_list_tests.h"

int should_create_list() {
  linked_list_t * list = 0;

  linked_list_init(list);

  printf("New list address: %d\n", (int) list);

  // assert(list);
  assert(list->size == 0);

  printf("List creation test passed.\n");

  return 0;
}

int run_linked_list_tests() {
  printf("\nRunning Linked List tests...\n");

  should_create_list();

  // ...

  return 0;
}
