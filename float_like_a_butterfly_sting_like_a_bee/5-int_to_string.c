#include <stdlib.h>
#include <stdio.h>

char *do_work(int, char**);

char  *add_digit(char digit, char **str) {
  int counter = 2; /* nonzero because null terminator and extension */
  char *strc = *str;
  while (**str != 0) {
    counter++;
    (*strc)++;
  }
  *(*(str)+counter-2) = digit;
  *str = realloc(*str, sizeof(char)*(counter));
/*  (*str)[counter-1] = 0; */
  printf("STRING: %s\n", *str);
  return *str;
}

char *int_to_string(int n)
{
  char *str = malloc(sizeof(char)*1);
  *str = 0;

	if (n < 0) {
    str = add_digit('-', &str);
		n = 0-n;
	}
	if (n == 0) {
    str = add_digit('0', &str);
	}
	else {
		str = do_work(n, &str);
	}
  return str;
}

char *do_work(int n, char **str)
{
	int divisor = 1;
	int a = n;
	while (a > 9) {
		a /= 10;
		divisor *= 10;
	}

	while (n > 0) {
		int to_print = n / divisor;
		n -= to_print * divisor;
		divisor /= 10;
	  *str = add_digit('0' + to_print, str);

	}
  return *str;
}
