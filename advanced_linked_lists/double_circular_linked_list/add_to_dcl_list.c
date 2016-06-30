#include "list.h"

#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dcl_list(List **list, char *str);
int add_begin_dcl_list(List **list, char *str);


/* Add element to the end of the list */
int add_end_dcl_list(List **list, char *str)
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


/* Add element to the start of the list */
int add_begin_dcl_list(List **list, char *str)
{
  List *newlist;
  List *start = *list;
  if (list == NULL) return 1;
  newlist = (List *) malloc(sizeof(List));
  if (newlist == NULL) return 1;
  newlist->str = strdup(str);
  if (*list == NULL) {
    newlist->next = newlist;
    newlist->prev = newlist;
    *list = newlist;
  } else {
    while (start->next != *list) {
      start = start->next;
    }
    newlist->next = start->next;
    newlist->prev = start;
    start->next->prev = newlist;
    start->next = newlist;
    *list = newlist;
  }
  return 0;
}
