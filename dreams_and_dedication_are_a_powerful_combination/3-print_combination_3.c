#include "my_functions.h"

void print_combination_3()
{
	char num, bum, rum;
	for (num = '0'; num < '8'; num++) {
		for (bum = num+1; bum < '9'; bum++) {
			for (rum = bum+1; rum <= '9'; rum++) {
				print_char(num);
				print_char(bum);
				print_char(rum);
				if (num != '7' || bum != '8' || rum != '9') {
					print_char(',');
					print_char(' ');
				}
			}
		}
	}
}
