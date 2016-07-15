void insertion_sort(int *array, int size) {
  int i;
  int j;
  for (i=1 ; i<size; i++) {
    j = i;
    while (j>0 && array[j-1] > array[j]) {
      array[j] = array[j] ^ array[j-1];
      array[j-1] = array[j] ^ array[j-1];
      array[j] = array[j] ^ array[j-1];
      j--;
    }
  }
}
