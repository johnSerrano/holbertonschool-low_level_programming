#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int str_len(char *str);
char *string_copy(char *dest, char *src);
char *do_work(long long, char*, int);
char *add_digit(char digit, char *str);
char *int_to_string(long long n, int base);
char *str_cat(char *dest, char *src);

/*
void main() {
	char *result = int_to_string(30, 16);
	printf("%s\n", result);
}
*/

/*
 * Function to change an int to a string
 * CHECKED: functions, length, width, brackets
 */
char *int_to_string(long long n, int base)
{
	char *str = malloc(sizeof(char)*1);
	*str = 0;

	if (n < 0) {
		str = add_digit('-', str);
	} else {
		n = 0-n;
	}
	if (n == 0) {
		str = add_digit('0', str);
	}
	else {
		str = do_work(n, str, base);
	}
	return str;
}

/*
 * Function to add a digit to TODO
 */
char *add_digit(char digit, char *str)
{
	char *newdigit = malloc(2*sizeof(char));
	char *scpy = malloc(sizeof(char) * (str_len(str) + 2));
	newdigit[0] = digit;
	newdigit[1] = 0;
	scpy = string_copy(scpy, str);
	scpy = str_cat(scpy, newdigit);
	free(str);
	free(newdigit);
	return scpy;
}

/*
 * Function to do??? TODO
 */
char *do_work(long long n, char *str, int base)
{
	long long divisor = 1;
	long long a = n;
	while (a < -1 * (base-1)) {
		a /= base;
		divisor *= base;
	}

	while (n < 0) {
		long long to_print = n / divisor;
		n -= to_print * divisor;
		divisor /= base;
		to_print = 0-to_print;
		if (to_print > 9) {
			to_print -= 10;
			str = add_digit('a' + to_print, str);
		} else {
			str = add_digit('0' + to_print, str);
		}
	}
	return str;
}

/*
 * Function get the length of a char *
 */
int str_len(char *str)
{
	int i=0;
	for (i=0; str[i]!=0; i++) {}
	return i;
}
