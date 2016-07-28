#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int ntree_insert(NTree **tree, char **parents, char *data);
void print_ntree(NTree *);
void print_tree_recurse(NTree *tree, int tabs);

int main() {
  /*test insert*/
  NTree *tree = NULL;
  ntree_insert(&tree, NULL, "/");

}

void print_ntree(NTree *tree)
{
  if (tree == NULL || tree->str == NULL) {
    printf("NULL\n");
    return;
  }
  print_tree_recurse(tree, 0);
}

void print_tree_recurse(NTree *tree, int tabs)
{
  int i = 0;
  List *ptr;
  if (tree == NULL) {
    return;
  }
  for (i=0 ; i<tabs ; i++) {
    printf("\t");
  }
  if (tree->str == NULL){
    printf("NULL\n");
  }
  printf("%s\n", tree->str);
  for (ptr = tree->children; ptr != NULL; ptr++) {
    print_tree_recurse(ptr->node, tabs+1);
  }
}
