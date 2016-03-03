int str_len(char *s) {
	int counter = 0;
	while (*s != 0) {
		counter++;
		s++;
	}
	return (counter);
}
