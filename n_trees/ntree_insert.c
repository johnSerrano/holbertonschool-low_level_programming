#include "tree.h"
#include <stdlib.h>
#include <string.h>

int ntree_insert(NTree **tree, char **parents, char *data)
{
  List **ptr;
  List *tmp;
  int i;
  if (*tree == NULL) {
    /* create tree */
    *tree = malloc(sizeof(NTree));
    if (*tree == NULL) return 1;
    /* add data as root node */
    (*tree)->str = strdup(data);
    (*tree)->children = NULL;
    return 0;
  } else {
    ptr = &((*tree)->children);

    /* if parents[0] or parents is null and there is already a root,
       we have a problem */
    for (i=0 ; parents[i] != NULL ; i++)
      /* if parents[0] is null add data as node */
      /* for node in ntrees list*/
      if (parents[i+1] == NULL) {
        /*insert here*/
        tmp = *ptr;
        *ptr = malloc(sizeof(List));
        (*ptr)->next = tmp;
        (*ptr)->node = malloc(sizeof(NTree));
        (*ptr)->node->str = strdup(data);
        (*ptr)->node->children = NULL;
        return 0;
      } else {
        /* find child where str == parents[i]*/
        while ((*ptr)->next != NULL && strcmp((*ptr)->node->str, parents[i]) != 0) {
          *ptr = (*ptr)->next;
        }
        *ptr = (*ptr)->node->children;
      }
    }
  return 0;
}
