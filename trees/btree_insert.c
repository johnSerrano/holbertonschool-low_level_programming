#include "tree.h"
#include "stdlib.h"
#include "string.h"


int btree_insert(BTree **tree, char *data)
{
  BTree *ptr;
  if (ptr == NULL) return 1;
  if (*tree == NULL) {
    ptr = malloc(sizeof(BTree));
    ptr->str = strdup(data);
    *tree = ptr;
  } else {
    return insert_recurse(*tree, data);
  }
  return 0;
}

int insert_recurse(BTree *tree, char *data)
{
  int diff;
  BTree *ptr;
  if (tree == NULL) return 1;
  diff = strcmp(tree->str, data);
  if (diff > 0) {
    if (tree->left != NULL)
      return insert_recurse(tree->left, data);
    ptr = malloc(sizeof(BTree));
    if (ptr == NULL) return 1;
    ptr->str = strdup(data);
    tree->left = ptr;
  } else {
    if (tree->right != NULL)
      return insert_recurse(tree->right, data);
    ptr = malloc(sizeof(BTree));
    if (ptr == NULL) return 1;
    ptr->str = strdup(data);
    tree->right = ptr;
  }
  return 0;
}
