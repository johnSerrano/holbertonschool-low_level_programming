//#include <stdio.h>

void reverse_array(int *a, int n)
{
	int i = 0;
	int tmp;
	for (i = 0; i < n/2; i++) {
		tmp = *(a+i);
		*(a+i) = *(((a+n)-i)-1);
		*(((a+n)-i)-1) = tmp;
	}
}
/*
void print_array(int*a, int n) {
  int i;
  for (i=0; i<n; i++) {
    printf("%d ", a[i]);
  }
}
*/
