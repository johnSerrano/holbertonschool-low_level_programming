#include "tree.h"
#include <stdlib.h>
#include <string.h>

int path_exists(NTree *tree, char **path)
{
  List *ptr;
  int i;
  for (i=1 ; path[i] != NULL ; i++) {
    ptr = tree->children;
    if (ptr == NULL) return 0;
    while (strcmp(ptr->node->str, path[i]) != 0) {
      if (ptr->next == NULL) return 0;
      ptr = ptr->next;
    }
    tree = ptr->node;
  }
  return 1;
}
