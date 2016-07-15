#include <stdio.h>

void quick_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {1024, 94111, 98, 12, 1024, 3232323};

  print_array(array, 6);
  quick_sort(array, 6);
  print_array(array, 6);
  return (0);
}

void print_array(int *array, int size) {
  int i;
  for (i=0 ; i<size-1 ; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d\n", array[size-1]);
}
