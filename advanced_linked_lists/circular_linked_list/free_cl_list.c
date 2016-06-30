#include "list.h"
#include <stdlib.h>

void free_cl_list(List *list) {
  List *start = list;
  List *slow = list;
  if (list == NULL) return;
  while (list->next != start) {
    slow = list;
    list = list->next;
    free(slow->str);
    free(slow);
  }
  free(list->str);
  free(list);
}
