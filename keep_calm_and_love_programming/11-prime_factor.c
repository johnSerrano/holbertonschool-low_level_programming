#include <stdio.h>

int main()
{
	unsigned long divisor = 2;
	unsigned long to_factor = 612852475143;
	unsigned long largest_factor = 1;
	
	while (to_factor != 1) {
		if (to_factor % divisor == 0) {
			to_factor /= divisor;
			if (divisor > largest_factor) {
				largest_factor = divisor;
			}
		}
		else {
			divisor++;
		}
	}
	printf("%lu\n", largest_factor);

	return (0);
}
