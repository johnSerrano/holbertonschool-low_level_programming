int len(char *s) {
	int counter = 0;
	while (*s != 0) {
		counter++;
		s++;
	}
	return (counter);
}

void reverse_string(char *s){
	int size = len(s);
	int i = 0;
	char tmp;
	for (i = 0; i < size/2; i++) {
		tmp = *(s+i);
		*(s+i) = *(((s+size)-i)-1);
		*(((s+size)-i)-1) = tmp;
	}
}
