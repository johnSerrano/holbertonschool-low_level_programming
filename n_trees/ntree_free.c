#include "tree.h"
#include <stdlib.h>

void ntree_free(NTree *tree)
{
  List *ptr;
  for (ptr = tree->children ; ptr != NULL ; ptr = ptr->next){
    ntree_free(ptr->node);
    free(ptr);
  }
  free(tree->str);
  free(tree);
}
