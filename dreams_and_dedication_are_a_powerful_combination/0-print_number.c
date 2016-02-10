#include "my_functions.h"

void  do_work(int);

void print_number(int n)
{
	/*
	 * This function prints an integer to the screen. 
	 */

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
