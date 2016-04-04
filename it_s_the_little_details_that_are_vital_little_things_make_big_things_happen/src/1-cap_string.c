char upper(char c)
{
	if (c >= 'a' && c <= 'z') c += ('A' - 'a');
	return(c);
}

char *cap_string(char *strc)
{
  char *str = strc;
  while (*strc != 0) {
    if (*strc == ' ' || *strc == '\n' || *strc == '\t' || strc == str) {
      if ((*(strc+1) >= 'a' && *(strc+1) <= 'z') ||
          (*(strc+1) >= 'A' && *(strc+1) <= 'Z')) {
        *(strc+1) = upper(*(strc+1));
      }
    }
    strc++;
  }
  return (str);
}
