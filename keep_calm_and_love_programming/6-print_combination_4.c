int print_char(int);

void print_combination_4() {
	char num, bum, rum, hum;
	for (num = '0', bum = '0'; bum < '9' || num <'9'; num++) {
		for (rum = num, hum = bum; hum <= '9'; rum++) {
			if (rum != num || hum != bum) {
				print_char(bum);
				print_char(num);
				print_char(' ');
				print_char(hum);
				print_char(rum);
				if (bum != '9' || num != '8' || hum != '9' || rum != '9') {
					print_char(',');
					print_char(' ');
				}
			}
			if (rum == '9') {
				hum++;
				rum = '0'-1;
			}
		} 
		if (num == '9') {
			bum++;
			num = '0'-1;
		}		
	}
}
