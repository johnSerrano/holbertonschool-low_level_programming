#include "my_functions.h"

void positive_or_not(int num_to_check)
{
	if (num_to_check > 0) { print_char('P'); }
	else if (num_to_check < 0) { print_char('N'); }
	else { print_char('Z'); }
}
