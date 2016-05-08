#include "list.h"
#include <stdlib.h>

int list_size(List *list) {
  int size = 1;
  if (list == NULL) return 0;
  while (list->next != NULL) {
    size++;
    list = list->next;
  }
  return size;
}
