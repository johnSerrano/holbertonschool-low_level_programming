int print_char(char);

int str_len(char *s) {
	int counter = 0;
	while (*s != 0) {
		counter++;
		s++;
	}
	return (counter);
}

void print_string_half(char *str)
{
  int len = (str_len(str)+1)/2;
  int i;
  for (i=0 ; i<len ; i++) {
    print_char(*(str+len+i));
  }
}
