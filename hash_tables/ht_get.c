#include "hashtable.h"
#include <stdlib.h>

char *get_string_dup(const char *str);
int get_string_comp(const char *str1, const char *str2);
int get_string_len(const char *str);

char *ht_get(HashTable *hashtable, const char *key) {
  int index = hash(key, hashtable->size);
  List *listptr = hashtable->array[index];
  while (listptr != NULL) {
    if (get_string_comp(listptr->key, key) == 0) {
      return get_string_dup(listptr->value);
    }
    listptr = listptr->next;
  }
  return NULL;
}

char *get_string_dup(const char *str) {
  char *newstr = malloc(sizeof(char) * (get_string_len(str)+1));
  int i = 0;
  for ( ; *(str + i) != 0; i++) {
    *(newstr+i) = *(str+i);
  }
  *(newstr+i) = 0;
  return newstr;
}

int get_string_comp(const char *str1, const char *str2) {
  int i;
  for (i=0 ; *(str1+i)!=0 || *(str2+i)!=0 ; i++) {
    if (*(str1+i) != *(str2+i)) return (*(str1+i) - *(str2+i));
  }
  return 0;
}

int get_string_len(const char *str) {
  int count = 0;
  while (*str != 0) {
    str++;
    count++;
  }
  return count;
}
