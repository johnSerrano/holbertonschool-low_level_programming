void swap_int(int *a, int *b) {
	int tmp = 0;
	int *c = &tmp;
	*c = *a;
	*a = *b;
	*b = *c;
}
