int print_char(int);
int absolutely(int);

void print_last_digit(int n)
{
	print_char('0' + absolutely(n % 10));
}


int absolutely(int n)
{
        if (n == -2147483648){
                return(n);
        }
        if (n < 0){
                return(0-n);
        }
        return(n);
}
