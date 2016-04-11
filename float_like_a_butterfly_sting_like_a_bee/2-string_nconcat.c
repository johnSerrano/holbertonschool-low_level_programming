#include <stdlib.h>

int slen(char *);

char *string_nconcat(char *s1, char *s2, int n) {
  int len = slen(s1) + slen(s2);
  int counter = 0;
  char *ret = malloc(sizeof(char)*(len+1));
  char *retc = ret;
  if (ret == NULL) return ret;
  while (*s1 != 0) {
    *retc = *s1;
    retc++;
    s1++;
  }
  while (*s2 != 0 && counter < n) {
    *retc = *s2;
    retc++;
    s2++;
    counter++;
  }
  *retc = 0;
  return ret;
}

int slen(char *str) {
  int total = 0;
  while (*str != 0) {
    total++;
    str++;
  }
  return total;
}
