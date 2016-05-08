#include <stdlib.h>
#include "list.h"

int strlength(char *str);
void copy_str(char *src, char *dest);

int add_node(List **list, char *str) {
  List *node_to_add = malloc(sizeof(List));
  List *curr = *list;

  node_to_add->next = curr;
  node_to_add->str = malloc(sizeof(char) * strlength(str));
  copy_str(str, node_to_add->str);

  if (node_to_add == NULL) return 1;
  if (curr == NULL) {
    *list = node_to_add;
    return 0;
  }

  *list = node_to_add;

  return 0;
}

int strlength(char *str) {
  int count = 0;
  while (str[count] != 0) count++;
  return (count + 1);
}

void copy_str(char *src, char *dest) {
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
