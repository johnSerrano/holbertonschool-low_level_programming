#include "hashtable.h"
#include <stdlib.h>

char *put_string_dup(const char *str);
int put_string_comp(const char *str1, const char *str2);
int put_string_len(const char *str);

int ht_put(HashTable *hashtable, const char *key, const char *value) {
  unsigned int index = hash(key, hashtable->size);
  List *listptr = hashtable->array[index];
  while (listptr != NULL) {
    if (put_string_comp(listptr->key, key) == 0) {
      /* This is an update */
      free(listptr->value);
      listptr->value = put_string_dup(value);
      return 0;
    }
    listptr = listptr->next;
  }
  /* Need to create new node */
  listptr = hashtable->array[index];
  hashtable->array[index] = malloc(sizeof(List));
  hashtable->array[index]->next = listptr;
  hashtable->array[index]->key = put_string_dup(key);
  hashtable->array[index]->value = put_string_dup(value);
  return 0;
}

char *put_string_dup(const char *str) {
  char *newstr = malloc(sizeof(char) * (put_string_len(str)+1));
  int i = 0;
  for ( ; *(str + i) != 0; i++) {
    *(newstr+i) = *(str+i);
  }
  *(newstr+i) = 0;
  return newstr;
}

int put_string_comp(const char *str1, const char *str2) {
  int i;
  for (i=0 ; *(str1+i)!=0 || *(str2+i)!=0 ; i++) {
    if (*(str1+i) != *(str2+i)) return (*(str1+i) - *(str2+i));
  }
  return 0;
}

int put_string_len(const char *str) {
  int count = 0;
  while (*str != 0) {
    str++;
    count++;
  }
  return count;
}
