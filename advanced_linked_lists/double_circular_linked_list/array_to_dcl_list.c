#include "list.h"
#include <stdlib.h>
#include <string.h>

int array_end_dcl_list(List **list, char *str);

/* create list from array */
List *array_to_dcl_list(char **array) {
  int i;
  List *list = NULL;
  for (i=0 ; array[i] != NULL ; i++) {
    array_end_dcl_list(&list, array[i]);
  }
  return list;
}

/* Add element to the end of the list */
int array_end_dcl_list(List **list, char *str)
{
  List *newlist;
  List *start = *list;
  if (list == NULL) return 1;
  newlist = (List *) malloc(sizeof(List));
  if (newlist == NULL) return 1;
  newlist->str = strdup(str);
  if (*list == NULL) {
    newlist->next = newlist;
    *list = newlist;
  } else {
    while (start->next != *list) {
      start = start->next;
    }
    newlist->next = start->next;
    newlist->prev = start;
    start->next->prev = newlist;
    start->next = newlist;
  }
  return 0;
}
