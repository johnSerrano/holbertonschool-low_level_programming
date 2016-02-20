#include <stdio.h>

int main()
{
	int i;
	long a = 1;
	long b = 2;
	long tmp;
	printf("1, 2");
	for (i = 0; i < 48; i++){
		tmp = a;
		a += b;
		b = tmp;
		printf(", ");
		printf("%ld", a);
	}
	return (0);
}
