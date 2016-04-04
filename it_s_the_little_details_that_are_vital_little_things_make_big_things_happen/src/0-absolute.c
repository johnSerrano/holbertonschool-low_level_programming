int absolute(int n)
{
	if (n == -2147483648){
		return(n);
	}
	if (n < 0){
		return(0-n);
	}
	return(n);
}
