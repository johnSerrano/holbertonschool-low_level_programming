#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int str_len(const char *str);
char *string_copy(char *dest, const char *src);
char *do_work(unsigned int, char*, unsigned int);
char *add_digit(char digit, char *str);
char *int_to_string(int n, unsigned int base);
char *str_cat(char *dest, char *src);

/*
 * Function to change an int to a string
 * CHECKED: functions, length, width, brackets
 */
char *int_to_string(int n, unsigned int base)
{
	char *str = malloc(sizeof(char)*1);
	*str = 0;

	if (n < 0) {
		str = add_digit('-', str);
		n *= -1;
	}
	if (n == 0) {
		str = add_digit('0', str);
	}
	else {
		str = do_work((unsigned int) n, str, base);
	}
	return str;
}

char *unsigned_to_string(unsigned int u, unsigned int base) {
	char *str = malloc(sizeof(char)*1);
	*str = 0;
	if (u == 0) {
		str = add_digit('0', str);
	}
	else {
		str = do_work(u, str, base);
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
 * Function
 */
char *do_work(unsigned int n, char *str, unsigned int base)
{
	unsigned int divisor = 1;
	unsigned int a = n;
	unsigned int to_print;

	while (a > base-1) {
		a /= base;
		divisor *= base;
	}
	while (n > 0) {
		to_print = n / divisor;
		n -= to_print * divisor;
		divisor /= base;
		if (to_print > 9) {
			to_print -= 10;
			str = add_digit('a' + to_print, str);
		} else {
			str = add_digit('0' + to_print, str);
		}
	}
	while (divisor >= 1) {
		divisor /= base;
		str = add_digit('0', str);
	}
	return str;
}

/*
 * Function get the length of a char *
 */
int str_len(const char *str)
{
	int i=0;
	for (i=0; str[i]!=0; i++) {}
	return i;
}
