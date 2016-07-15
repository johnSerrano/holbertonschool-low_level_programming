#include <stdio.h>

void swap(int *a, int *b);

void quick_sort_recurse(int *array, int begin, int size);

void quick_sort(int *array, int size) {
  return quick_sort_recurse(array, 0, size);
}

void quick_sort_recurse(int *array, int begin, int size) {
  int pivot = (begin + size)/2;
  int left = begin;
  int pivot_val = array[pivot];
  int right = size-1;
  if (size - begin < 2) {
    return;
  }
  while (left < right) {
    while (array[left] < pivot_val) left++;
    while (pivot_val < array[right]) right--;
    if (left < right) {
      swap(&array[left], &array[right]);
      if (array[left] == array[right]) {
        left++;
        right++;
      }
    }
  }
  quick_sort_recurse(array, begin, left);
  quick_sort_recurse(array, left, size);
}

void swap(int *a, int *b) {
  if (*a == *b) return;
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}
