#include <stdlib.h>
#include "list.h"

int strlength_6(char *str);
void copy_str_6(char *src, char *dest);
int list_size_6(List *list);
int add_node_6(List **list, char *str);

int insert_in_list(List **list, char *content, int index) {
  int pos = 0;
  List *ptr = *list;
  List *tmp;
  /* edge cases */
  if (index < 0) return 1;
  if (list_size_6(*list) <= index) return 1;
  if (index == 0) return add_node_6(list, content);

  /* -2 because we started on the first node and we want the node BEFORE where
   * we're going to insert
   */
  while (pos < index-2) {
    pos++;
    ptr = ptr->next;
  }
  tmp = ptr->next;

  ptr->next = malloc(sizeof(List));
  if (ptr->next == NULL) return 1;

  ptr->next->next = tmp;

  ptr->next->str = malloc(sizeof(char) * strlength_6(content));
  copy_str_6(content, ptr->next->str);
  return 0;
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

int add_node_6(List **list, char *str) {
  List *node_to_add = malloc(sizeof(List));
  List *curr = *list;

  node_to_add->next = curr;
  node_to_add->str = malloc(sizeof(char) * strlength_6(str));
  copy_str_6(str, node_to_add->str);

  if (node_to_add == NULL) return 1;
  if (curr == NULL) {
    *list = node_to_add;
    return 0;
  }

  *list = node_to_add;

  return 0;
}

int strlength_6(char *str) {
  int count = 0;
  while (str[count] != 0) count++;
  return (count + 1);
}

void copy_str_6(char *src, char *dest) {
  char *using_a_pointless_var_because_of_the_pointless_compilier_flags;
  while (*src != 0) {
    *dest = *src;
    src++;
    dest++;
  }
  *dest = 0;
  /* tricking compiler flags to allow this funciton to compile */
  using_a_pointless_var_because_of_the_pointless_compilier_flags = src;
  using_a_pointless_var_because_of_the_pointless_compilier_flags = dest;
  src = using_a_pointless_var_because_of_the_pointless_compilier_flags + 1;
}
