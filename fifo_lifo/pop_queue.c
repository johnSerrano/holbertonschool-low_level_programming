#include <stdlib.h>
#include "queue.h"

char *pop_queue(Queue **q)
{
  Queue *topop;
  char *data;
  if (q == NULL || *q == NULL) return NULL;
  topop = *q;
  data = topop->str;
  *q = topop->next;
  free(topop);
  return data;
}
