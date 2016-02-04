#include "my_functions.h"

void print_alphabet()
{
	/* prints the entire alphabet */
	int i;
	for (i=0; i<26; i++) {
		print_char('a' + i);
	}
}
