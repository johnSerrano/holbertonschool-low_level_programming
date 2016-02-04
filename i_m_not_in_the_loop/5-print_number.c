#include "my_functions.h"

void check_array(int cell, int *array)
{
	if (cell == 20) { return; }
	if (array[cell] == 10) {
		array[cell] = 0;
		array[cell + 1]++;
		check_array(cell + 1, array);
	}
}

void print_number(int n)
{
	int array[21] = {0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0};
	int i;
	int negative = 0;
	if (n < 0) {
		negative = 1;
		n = 0-n;
	}

	while (n > 0) {
		n--;
		array[0]++;
		check_array(0, array);
	}
	i=20;
	if (negative) { 
		print_char('-'); 
	}

	while(array[i] == 0 && i >=0) {
 		i--; 
	}

	if (i == -1) {
		print_char('0'); 
	}
	else {
		while(i >= 0) { 
			print_char('0' + array[i]); 
			i--; 
		}
	}	
}
