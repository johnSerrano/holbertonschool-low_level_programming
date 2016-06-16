#include <unistd.h>

int string_to_int(char *s);
int get_value(int, char *, char *);
int print_char(char c);
void print_row(int i, int len);

int main(int argc, char **argv)
{
	int i = 0;
	int len = 0;
	if (argc < 2) {
		return (1);
	}
	len = string_to_int(argv[1]) -1;

	for (i=0 ; i<=len; i++) {
		print_row(i, len);
	}
	return (0);
}

/* print one row of the cross */
void print_row(int i, int len)
{
	int j = 0;
	for (; j<=len ; j++) {
		if (i == len-i && j == i) {
			print_char('X');
		} else if (j == i) {
			print_char('\\');
		} else if (j == len-i) {
			print_char('/');
		} else {
			print_char(' ');
		}
	}
	print_char('\n');
}

/*
 * Function that converts string to int.
 */
int string_to_int(char *s)
{
	int positive = 1;
	char *start = s;
	char *end = s;
	while (*start != 0 && (*start < '0' || *start > '9')) {
		if (*start == '-') {
			positive *= -1;
		}
		start++;
	}

	if (*start == 0) {
		return (0);
	}

	end = start;
	while (*end >= '0' && *end <= '9') {
		end++;
	}
	end--;

	return (get_value(positive, start, end));
}

/*
 * Function that returns the value of a number
 * (positive or negative).
 */
int get_value(int positive, char *start, char *end)
{
	char *current_char;
	int i;
	long current_int;
	long total =0;

	for (current_char = start; current_char <= end; current_char++) {
		current_int = *current_char - '0';
		for (i = 0; i < end - current_char; i++)
			current_int *= 10;
		total += current_int;
		if (total * positive > 2147483647 || total * positive < -2147483648)
			return (0);
	}

	return (positive * (int) total);
}

/* print a character */
int print_char(char c)
{
      return (write(1, &c, 1));
}
