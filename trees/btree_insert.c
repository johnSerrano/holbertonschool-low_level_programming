#include "tree.h"
#include "stdlib.h"
#include "string.h"

void construct_btree(BTree **tree);

int btree_insert(BTree **tree, char *data)
{
  BTree *ptr;
  if (*tree == NULL) {
    construct_btree(&ptr);
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
    construct_btree(&ptr);
    if (ptr == NULL) return 1;
    ptr->str = strdup(data);
    tree->left = ptr;
  } else {
    if (tree->right != NULL)
      return insert_recurse(tree->right, data);
    construct_btree(&ptr);
    if (ptr == NULL) return 1;
    ptr->str = strdup(data);
    tree->right = ptr;
  }
  return 0;
}

void construct_btree(BTree **tree)
{
  *tree = malloc(sizeof(BTree));
  (*tree)->left = NULL;
  (*tree)->right = NULL;
  (*tree)->str = NULL;
}
