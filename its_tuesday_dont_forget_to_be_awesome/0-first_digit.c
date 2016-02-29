char  do_work(int);

char first_digit(int n)
{
	/*
	 * This function prints an integer to the screen. 
	 */

	if (n > 0) {
		n = 0-n;
	}
	if (n == 0) {
		return('0');
	}
	else {
		return(do_work(n));
	}
}

char do_work(int n)
{
	int divisor = 1;
	int a = n;
	int to_print;
	while (a < -9) {
		a /= 10;
		divisor *= 10;
	}

	to_print = n / divisor;
	n += to_print * divisor;
	divisor /= 10;
	return('0' + (-1*to_print));	
}
