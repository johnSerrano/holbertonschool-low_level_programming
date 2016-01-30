#include "unistd.h"

int main()
{
	write(1, "Hello, C\n", 9);
	return 0;
}
