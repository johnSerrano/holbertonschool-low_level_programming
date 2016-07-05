#include "hashtable.h"
#include <stdlib.h>

HashTable *ht_create(unsigned int size) {
  unsigned int i;
  HashTable *ht = malloc(sizeof(HashTable));
  ht->size = size;
  ht->array = malloc(sizeof(List *) * size);
  for (i = 0; i < size; i++) {*(ht->array+i) = NULL;}
  return ht;
}
