#include "tree.h"
#include <stdlib.h>

void btree_free(BTree *tree) {
  if (tree == NULL) return;
  // if (tree->left != NULL)
    btree_free(tree->left);
  // if (tree->right != NULL)
    btree_free(tree->right);
  if (tree->str != NULL)
    free(tree->str);
  free(tree);
}
