#include "list.h"

#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dl_list(List **list, char *str);
int add_begin_dl_list(List **list, char *str);


/* Add element to the end of the list */
int add_end_cl_list(List **list, char *str)
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
    start->next = newlist;
  }
  return 0;
}


/* Add element to the start of the list */
int add_begin_cl_list(List **list, char *str)
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
    start->next = newlist;
    *list = newlist;
  }
  return 0;
}
