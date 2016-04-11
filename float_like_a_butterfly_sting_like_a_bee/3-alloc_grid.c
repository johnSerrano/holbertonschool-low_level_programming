#include <stdlib.h>
int **alloc_grid(int width, int height) {
  int **arrays = malloc(sizeof(int *) * height);
  int i = 0;
  if (arrays == NULL) return NULL;
  for ( ; i<width ; i++) {
    arrays[i] = malloc(sizeof(int) * width);
    if (arrays[i] == NULL) return NULL;
  }
  return arrays;
}
