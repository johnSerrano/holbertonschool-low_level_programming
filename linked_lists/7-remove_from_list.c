#include <stdlib.h>
#include "list.h"

void free_node(List *node);
int list_size_6(List *list);

void remove_from_list(List **list, int index) {
  int pos = 0;
  List *ptr = *list;
  List *tmp;

  if (index < 0) return;
  if (list_size_6(*list) <= index) return;
  if (index == 0) {
    *list = (*list)->next;
    return;
  }

  /* -2 because we started on the first node and we want the node BEFORE where
   * we're going to insert
   */
  while (pos < index-2) {
    pos++;
    ptr = ptr->next;
  }
  tmp = ptr->next->next;
  free_node(ptr->next);
  ptr->next = tmp;
}

void free_node(List *node) {
  free(node->str);
  free(node);
}

int list_size_6(List *list) {
  int size = 1;
  if (list == NULL) return 0;
  while (list->next != NULL) {
    size++;
    list = list->next;
  }
  return size;
}
