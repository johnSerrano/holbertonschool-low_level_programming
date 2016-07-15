#include <stdio.h>

void insertion_sort(int *, int);
void print_array(int *, int);

int main(void)
{
  int array[] = {402, 94111, 98, 12, 1024};

  print_array(array, 5);
  insertion_sort(array, 5);
  print_array(array, 5);
  return (0);
}

void print_array(int *array, int size) {
  int i;
  for (i=0 ; i<size-1 ; i++) {
    printf("%d, ", array[i]);
  }
  printf("%d\n", array[size-1]);
}
