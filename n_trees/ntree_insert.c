#include "tree.h"
#include <stdlib.h>
#include <string.h>

NTree *findnode(NTree *tree, char **parents);

int ntree_insert(NTree **tree, char **parents, char *data)
{
  NTree *nuclear_parent;
  List *ptr;
  if (*tree == NULL) {
    /* create tree */
    *tree = (NTree *) malloc(sizeof(NTree));
    if (*tree == NULL) return 1;
    /* add data as root node */
    (*tree)->str = strdup(data);
    (*tree)->children = NULL;
    return 0;
  } else {
    nuclear_parent = findnode(*tree, parents);
    ptr = nuclear_parent->children;
    nuclear_parent->children = (List *) malloc(sizeof(List));
    nuclear_parent->children->next = ptr;
    nuclear_parent->children->node = (NTree *) malloc(sizeof(NTree));
    nuclear_parent->children->node->str = strdup(data);
    nuclear_parent->children->node->children = NULL;
  }
  return 0;
}

NTree *findnode(NTree *tree, char **parents)
{
  List *ptr;
  int i;
  for (i=1 ; parents[i] != NULL ; i++) {
    ptr = tree->children;
    while (strcmp(ptr->node->str, parents[i]) != 0) {
      ptr = ptr->next;
    }
    tree = ptr->node;
  }
  return tree;
}
