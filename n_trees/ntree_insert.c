#include "tree.h"
#include <stdlib.h>
#include <string.h>

int ntree_insert(NTree **tree, char **parents, char *data)
{
  List *ptr = (*tree)->children;
  if (*tree == NULL) {
    /* create tree */
    /* add data as root node */
  } else {
    /* if parents[0] or parents is null and there is already a root,
       we have a problem */
    int i;
    for (i=0 ; parents[i] != NULL ; i++)
      /* if parents[0] is null add data as node */
      /* for node in ntrees list*/
      while (strcmp(ptr->node->str, data) != 0 || ptr != NULL) {
        ptr = ptr->next;
      }
      ptr->node->str = strdup(data);
  }
}
