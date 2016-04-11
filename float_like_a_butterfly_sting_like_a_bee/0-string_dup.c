#include <stdlib.h>

char *string_dup(char *str) {
  char *strc = str;
  char *ret;
  char *retc;
  int strln = 0;
  while (*strc != 0) {
    strc++;
    strln++;
  }
  ret = malloc(sizeof(char) * (strln+1));
  if (ret == NULL) return ret;
  retc = ret;
  strc = str;
  while (*strc != 0) {
    *retc = *strc;
    retc++;
    strc++;
  }
  *retc=0;
  return ret;
}
