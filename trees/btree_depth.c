#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_depth_recurse(BTree *tree, int depth);
int max(int a, int b);

int btree_depth(BTree *tree)
{
  return btree_depth_recurse(tree, -1);
}

int btree_depth_recurse(BTree *tree, int depth) {
  if (tree == NULL) return depth;
  depth += 1;
  return max(btree_depth_recurse(tree->left, depth),
             btree_depth_recurse(tree->right, depth));
}

int max(int a, int b) {
  return (a > b) ? a : b;
}
