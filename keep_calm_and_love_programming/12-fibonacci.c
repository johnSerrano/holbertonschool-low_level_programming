#include <stdio.h>

void recurse(long, long, long, long, int); 

int main()
{
	printf("1, 2");
	recurse(2, 0, 1, 0, 0);
	return(0);
}



void recurse(long a0, long a1, long b0, long b1, int count) {
	long tmp0 = a0;
	long tmp1 = a1;

	a1 += ((unsigned long)a0 + (unsigned long)b0) / 1000000000;
	a0 = (a0 + b0) % 1000000000;
	a1 = a1 + b1; 
	if (a1 == 0) {
		printf(", %ld", a0);
	}
	else {
		printf(", %ld%09ld", a1, a0);
	}
	if (count < 95) recurse(a0, a1, tmp0, tmp1, count+1);
}
