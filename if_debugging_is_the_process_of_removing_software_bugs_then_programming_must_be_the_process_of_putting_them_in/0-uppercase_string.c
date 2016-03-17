char uppercase(char c)
{
	if (c >= 'a' && c <= 'z') c += ('A' - 'a');
	return(c);
}


char *uppercase_string(char *str)
{
  char *ret = str;
  while (*str != 0) {
    *str = uppercase(*str);
    str++;
  }
  return (ret);
}
