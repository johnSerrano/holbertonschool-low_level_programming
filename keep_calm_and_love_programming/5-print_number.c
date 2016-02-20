void  do_work(int);
int print_char(int);

void print_number(int n)
{
	/*
	 * This function prints an integer to the screen. 
	 */
	int int_min_boolean = 0;

	if (n == -2147483648){
		n = -214748364;
		int_min_boolean = 1;
	}
	if (n < 0) {
		print_char('-');
		n = 0-n;
	}
	if (n == 0) {
		print_char('0');
	}
	else {
		do_work(n);
	}
	if (int_min_boolean == 1) {
		print_char('0' + 8);
	}
}

void do_work(int n)
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
