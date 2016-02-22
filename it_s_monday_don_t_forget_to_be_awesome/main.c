#include <stdio.h>

char lowercase(char);

int main(void)
{
	char c;
	c = lowercase('A');
	printf("%c\n", c);
	c = lowercase('a');
	printf("%c\n", c);
	c = lowercase('^');
	printf("%c\n", c);
	c = lowercase('~');
	printf("%c\n", c);
	c = lowercase('Z');
	printf("%c\n", c);
	return (0);
}
