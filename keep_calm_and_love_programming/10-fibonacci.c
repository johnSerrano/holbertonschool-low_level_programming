#include <stdio.h>

int main()
{
	int i;
	long a = 1;
	long b = 2;
	long tmp;
	unsigned long total = 0;
	for (i = 0; a < 4000000; i++){
		tmp = a;
		a += b;
		b = tmp;
		if (a % 2 == 0) {
			total += a;
		}
	}
	printf("%lu\n", total + 2);
	return (0);
}
