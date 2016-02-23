#include <limits.h>

char first_digit(int);

int main()
{
	print_char(first_digit(2));
	print_char(first_digit(-13));
	print_char(first_digit(INT_MIN));
	print_char(first_digit(1234));
	print_char(first_digit(4321));
	return (0);
}
