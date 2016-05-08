#include "list.h"
#include <stdlib.h>

void free_node(List *node);

void free_list(List *list) {
  List *prev;
  while (list != NULL) {
    prev = list;
    list = list->next;
    free_node(prev);
  }
}

void free_node(List *node) {
  free(node->str);
  free(node);
}
