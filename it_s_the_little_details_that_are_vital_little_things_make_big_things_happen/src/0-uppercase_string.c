char upperc(char c)
{
	if (c >= 'a' && c <= 'z') c += ('A' - 'a');
	return(c);
}


char *uppercase_string(char *str)
{
  char *ret = str;
  while (*str != 0) {
    *str = upperc(*str);
    str++;
  }
  return (ret);
}
