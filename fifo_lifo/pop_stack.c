#include <stdlib.h>
#include "stack.h"

char *pop_stack(Stack **q)
{
  Stack *topop;
  char *data;
  if (q == NULL || *q == NULL) return NULL;
  topop = *q;
  data = topop->str;
  *q = topop->next;
  free(topop);
  return data;
}
