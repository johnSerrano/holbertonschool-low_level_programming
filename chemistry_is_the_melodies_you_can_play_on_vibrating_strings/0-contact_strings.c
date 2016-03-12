char *concat_strings(char *dest, const char *src){
  char *begin = dest;

  while (*dest != 0) dest++;
  while (*src != 0) {
    *dest = *src;
    src++; dest++;
  }
  *dest = *src;
  return (begin);
}
