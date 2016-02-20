int print_char(char);

void print_combination_2()
{
	char num, bum;
	for (num = '0'; num < '9'; num++) {
		for (bum = num+1; bum <= '9'; bum++) {
			print_char(num);
			print_char(bum);
			if (num != '8' || bum != '9') {
				print_char(',');
				print_char(' ');
			}
		}
	}
}
