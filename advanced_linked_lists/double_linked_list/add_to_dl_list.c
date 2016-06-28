#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dl_list(List **list, char *str);
int add_begin_dl_list(List **list, char *str);


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


/* Add element to the start of the list */
int add_begin_dl_list(List **list, char *str)
{
  List *newlist;
  if (list == NULL) return 1;
  newlist = (List *) malloc(sizeof(List));
  if (newlist == NULL) return 1;
  newlist->str = strdup(str);
  newlist->prev = NULL;
  if (*list == NULL) {
    newlist->next = NULL;
    *list = newlist;
  } else {
    newlist->next = *list;
    (*list)->prev = newlist;
    *list = newlist;
  }
  return 0;
}
