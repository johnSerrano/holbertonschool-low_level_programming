#include "tree.h"
#include <string.h>
#include <stdlib.h>

/*TODO test this function*/
char *btree_find(BTree *tree, char *str)
{
  int diff = strcmp(tree->str, str);
  if (diff > 0) {
    if (tree->left == NULL) return NULL;
    return btree_find(tree->left, str);
  } else if (diff < 0) {
    if (tree->right == NULL) return NULL;
    return btree_find(tree->right, str);
  } else {
    return tree->str;
  }
  return NULL;
}
