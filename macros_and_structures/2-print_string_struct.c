#include "str_struct.h"

int print_char(char);
void  do_work(int);
void print_number(int n);

/* prints a string struct. */
void print_string_struct(struct String *str) {
  char *strc = str->str;
  while (*strc != 0) print_char(*(strc++));
  print_char(',');
  print_char(' ');
  print_number(str->length);
  print_char('\n');
}


/*
* This function prints an integer to the screen.
*/
void print_number(int n)
{

	if (n < 0) {
		print_char('-');
		n = 0-n;
	}
	if (n == 0) {
		print_char('0');
	}
	else {
		do_work(n);
	}
}

/* worker function for print number. Don't use. */
void do_work(int n)
{
	int divisor = 1;
	int a = n;
	while (a > 9) {
		a /= 10;
		divisor *= 10;
	}

	while (n > 0) {
		int to_print = n / divisor;
		n -= to_print * divisor;
		divisor /= 10;
		print_char('0' + to_print);
	}
}
