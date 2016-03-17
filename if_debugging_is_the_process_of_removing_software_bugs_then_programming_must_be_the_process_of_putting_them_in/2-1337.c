char leetchar(char c) {
  switch (c) {
    case 'a':
    case 'A':
      return ('4');
    break;
    case 'e':
    case 'E':
      return ('3');
    break;
    case 'o':
    case 'O':
      return ('0');
    break;
    case 't':
    case 'T':
      return ('7');
    break;
    case 'l':
    case 'L':
      return ('1');
    break;
    default:
      return (c);
  }
}

char *leet(char *str) {
  char * ret = str;
  while (*str != 0) {
    *str = leetchar(*str);
    str++;
  }
  return (ret);
}
