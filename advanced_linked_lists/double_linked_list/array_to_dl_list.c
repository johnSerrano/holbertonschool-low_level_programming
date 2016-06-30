#include "list.h"
#include <stdlib.h>
#include <string.h>

int add_end_dl_list(List **list, char *str);

/* create list from array */
List *array_to_dl_list(char **array) {
  int i;
  List *list = NULL;
  for (i=0 ; array[i] != NULL ; i++) {
    add_end_dl_list(&list, array[i]);
  }
  return list;
}

/* Add element to the end of the list */
int add_end_dl_list(List **list, char *str)
{
  List *ptr;
  List *newlist;
  if (list == NULL) return 1;
  newlist = (List *) malloc(sizeof(List));
  if (newlist == NULL) return 1;
  newlist->str = strdup(str);
  newlist->next = NULL;
  if (*list == NULL) {
    newlist->prev = NULL;
    *list = newlist;
  }
  else {
    ptr = *list;
    while (ptr->next != NULL) {
      ptr = ptr->next;
    }
    newlist->prev = ptr;
    ptr->next = newlist;
  }
  return 0;
}
