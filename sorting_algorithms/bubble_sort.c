void bubble_sort(int *array, int size) {
  int i;
  int j;
  for (i=0; i<size-1; i++) {
    for (j=0; j<size-1; j++) {
      if (array[j] > array[j+1]) {
        array[j] = array[j] ^ array[j+1];
        array[j+1] = array[j] ^ array[j+1];
        array[j] = array[j] ^ array[j+1];
      }
    }
  }
}
