#include <stdlib.h>
#include "str_struct.h"

char *copy_string(char *str);
int strlength(char *str);

/* returns a String struct from a char * */
struct String *string_to_struct(char *str) {
  struct String *ret = malloc(sizeof(struct String));
  if (ret == NULL) return NULL;
  ret->str = copy_string(str);
  if (ret->str == NULL) return NULL;
  ret->length = strlength(str);
  return ret;
}

/* Get length of string including null terminator */
int strlength(char *str) {
  int len = 0;
  while (*str != 0) {
    str++;
    len++;
  }
  return len;
}

/* Return a copy of a string */
char *copy_string(char *str) {
  int len = strlength(str);
  char *new_str = malloc(sizeof(char *) * (len+1));
  char *ret = new_str;
  while (*str != 0) {
    *new_str = *str;
    new_str++;
    str++;
  }
  *new_str = 0;
  return ret;
}
