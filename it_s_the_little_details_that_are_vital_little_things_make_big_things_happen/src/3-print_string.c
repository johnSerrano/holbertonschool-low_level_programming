int print_char(char);
void print_string(char *str) {
	while (*str != 0) {
		print_char(*str);
		str++;
	}
}
