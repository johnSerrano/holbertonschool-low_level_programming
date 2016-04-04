int print_char(int);
void positive_or_not(int n)
{
	/* informs if a number is positive or not */
	if (n > 0) { print_char('P'); }
	else if (n < 0) { print_char('N'); }
	else { print_char('Z'); }
}
