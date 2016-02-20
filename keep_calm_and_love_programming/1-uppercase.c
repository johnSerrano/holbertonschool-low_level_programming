char uppercase(char c)
{
	if (c >= 'a' && c <= 'z') c += ('A' - 'a');
	return(c);
}
