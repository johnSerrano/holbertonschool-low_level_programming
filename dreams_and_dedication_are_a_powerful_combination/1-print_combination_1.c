#include "my_functions.h"

void print_combination_1()
{
	char num;
	for (num = '0'; num < '9'; num++) {
		print_char(num);
		print_char(',');
		print_char(' ');
	}
	print_char(num);
}
