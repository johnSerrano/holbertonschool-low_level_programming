#include "my_functions.h"

void print_tebahpla(void) 
{
	/* prints the alphabet backwards. Program is conclusively sober. */
	int i;
	for (i=0; i<26; i++) {
		print_char('z'-i);
	}
}
