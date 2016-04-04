int print_char(char);

void donwork(int n)
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
		print_char('0' + to_print);
	}
}

void printnumber(int n)
{
	if (n < 0) {
		print_char('-');
		n = 0-n;
	}
	if (n == 0) {
		print_char('0');
	}
	else {
		donwork(n);
	}
}

void print_array(int *a, int n) {
  int i;
  for (i=0 ; i<n ; i++) {
    if (i != 0) {
      print_char(' ');
      print_char(',');
    }
    printnumber(*(a+i));
  }
  print_char('\n');
}
