#include "my_functions.h"

void check_array(int cell, int *array)
{
	/* checks array for double digit columns */
	if (cell == 20) { return; }
	if (array[cell] == 10) {
		array[cell] = 0;
		array[cell + 1]++;
		check_array(cell + 1, array);
	}
}

void print_array(int array[21], int negative) 
{
	/*prints the array*/
	int i=20;
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

void print_number(int n)
{
	/*
	 * This function prints an integer to the screen. 
	 * It is capable of handling any integer stored with up to 64 bits.
	 */
	int array[21] = {0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0, 0, 0, 0, 0, 
			 0};
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
	print_array(array, negative);
}
