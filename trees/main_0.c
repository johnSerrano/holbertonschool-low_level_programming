#include "tree.h"
#include "stdio.h"

int btree_insert(BTree **tree, char *data);
void print_preorder(BTree *tree);
int test_insert();
char *btree_find(BTree *, char *);
void test_find();
BTree *array_to_btree(char **array);
void test_array_insert();
void btree_free(BTree *);
void test_depth();
int btree_depth(BTree *tree);

int main() {
  test_insert();
  test_find();
  test_array_insert();
  test_depth();
}

void test_array_insert() {
  char *array[] = {
    "q - 1",
    "w - 6",
    "e - 2",
    "r - 7",
    "t - 8",
    "y - 10",
    "u - 9",
    "i - 3",
    "o - 4",
    "p - 5",
    NULL
  };
  BTree *tree = array_to_btree(array);
  printf("The numbers should be in ascending order.\n");
  if (tree == NULL)
    printf("ERROR: Tree is NULL\n");
  else
    print_preorder(tree);
  btree_free(tree);
}

int test_insert() {
  BTree *tree = NULL;
  printf("The numbers should be in ascending order.\n");
  btree_insert(&tree, "q - 1");
  btree_insert(&tree, "w - 6");
  btree_insert(&tree, "e - 2");
  btree_insert(&tree, "r - 7");
  btree_insert(&tree, "t - 8");
  btree_insert(&tree, "y - 10");
  btree_insert(&tree, "u - 9");
  btree_insert(&tree, "i - 3");
  btree_insert(&tree, "o - 4");
  btree_insert(&tree, "p - 5");
  print_preorder(tree);
  btree_free(tree);
  return 0;
}

void test_depth() {
  BTree *tree = NULL;
  printf("Testing depth.\n");
  btree_insert(&tree, "q - 1");
  printf("Depth: %d, Expected: 0\n", btree_depth(tree));
  btree_insert(&tree, "w - 6");
  printf("Depth: %d, Expected: 1\n", btree_depth(tree));
  btree_insert(&tree, "e - 2");
  printf("Depth: %d, Expected: 1\n", btree_depth(tree));
  btree_insert(&tree, "r - 7");
  printf("Depth: %d, Expected: 2\n", btree_depth(tree));
  btree_insert(&tree, "t - 8");
  printf("Depth: %d, Expected: 3\n", btree_depth(tree));
  btree_insert(&tree, "y - 10");
  printf("Depth: %d, Expected: 3\n", btree_depth(tree));
  btree_insert(&tree, "u - 9");
  printf("Depth: %d, Expected: 4\n", btree_depth(tree));
  btree_insert(&tree, "i - 3");
  printf("Depth: %d, Expected: 4\n", btree_depth(tree));
  btree_insert(&tree, "o - 4");
  printf("Depth: %d, Expected: 4\n", btree_depth(tree));
  btree_insert(&tree, "p - 5");
  printf("Depth: %d, Expected: 4\n", btree_depth(tree));
  btree_free(tree);
}

void test_find() {
  BTree *tree = NULL;
  printf("Testing Find: should print \"found\".\n");
  btree_insert(&tree, "Not found");
  btree_insert(&tree, "Nope, not found");
  btree_insert(&tree, "Can't be found");
  btree_insert(&tree, "found");
  btree_insert(&tree, "Hahaha not found");
  btree_insert(&tree, "found! Not :)");
  printf("%s\n", btree_find(tree, "found"));
  if (btree_find(tree, "doesn't exist") != NULL) {
    printf("Not found should return NULL, but doesn't.\n");
  } else {
    printf("Not found correctly returns NULL.\n");
  }
  // print_preorder(tree);
  btree_free(tree);
}

void print_preorder(BTree *tree) {
  if (tree == NULL) return;
  printf("%s\n", tree->str);
  print_preorder(tree->left);
  print_preorder(tree->right);
}
