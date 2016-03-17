char rotchar(char c) {
  int offset = 0;
  if (c >= 'A' && c <= 'Z') {
    offset = 32;
    c += 32;
  }
  if (c >= 'a' && c <= 'z') {
    c = ((c-'a'+13)%26) + 'a';
  }
  return (c - offset);
}

char *rot13(char *str)
{
  char * ret = str;
  while (*str != 0) {
    *str = rotchar(*str);
    str++;
  }
  return (ret);
}
