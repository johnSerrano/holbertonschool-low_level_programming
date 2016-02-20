#include <limits.h>
#include <stdio.h>

int absolute(int);
char uppercase(char);
void print_last_digit(int);
void print_to_98(int);
void print_combination_2();
void print_number(int);
void print_combination_4();

int main()
{
	int n;
	char c;
	n = absolute(-1);
	printf("%d\n", n);
	n = absolute(10);
	printf("%d\n", n);
	n = absolute(0);
	printf("%d\n", n);
	n = absolute(INT_MAX);
	printf("%d\n", n);
	n = absolute(INT_MIN + 1);
	printf("%d\n", n);
	n = absolute(INT_MIN);
	printf("%d\n", n);

	c = uppercase('a');
	printf("%c\n", c);
	c = uppercase('h');
	printf("%c\n", c);
	c = uppercase('A');
	printf("%c\n", c);
	c = uppercase('{');
	printf("%c\n", c);

	print_last_digit(98);
	print_last_digit(0);
	print_last_digit(-402);

	printf("\n");
	
	print_to_98(90);
	print_to_98(-10);
	print_to_98(98);
	print_to_98(113);
	
	printf("\n");
	
	print_combination_2();
	
	printf("\n\n");

	print_number(INT_MIN);
	printf("\n");
	print_number(7);
	printf("\n\n");

	print_combination_4();

	printf("\n\n");

	return(0);
}
