#include "hashtable.h"
#include <stdlib.h>

void ht_free(HashTable *hashtable){
  unsigned int i = 0;
  List *listptr;
  List *prev;
  for ( ; i<hashtable->size ; i++) {
    listptr = hashtable->array[i];
    while (listptr != NULL) {
      free(listptr->key);
      free(listptr->value);
      prev = listptr;
      listptr = listptr->next;
      free(prev);
    }
  }
  free(hashtable->array);
  free(hashtable);
  return;
}
