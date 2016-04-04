int len(char *s) {
	int counter = 0;
	while (*s != 0) {
		counter++;
		s++;
	}
	return (counter);
}

char *nconcat_strings(char *dest, const char *src, int n)
{
  int dest_len = len(dest);
  int i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[dest_len + i] = src[i];
  dest[dest_len + i] = '\0';

  return dest;
}
