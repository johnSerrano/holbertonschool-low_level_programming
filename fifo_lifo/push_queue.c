#include <stdlib.h>
#include <string.h>
#include "queue.h"

int push_queue(Queue **q, char *str)
{
  Queue *pushptr = *q;
  if (pushptr == NULL) {
    pushptr = (Queue *) malloc(sizeof(Queue));
    *q = pushptr;
  } else {
    while (pushptr->next != NULL)
      pushptr = pushptr->next;
    pushptr->next = (Queue *) malloc(sizeof(Queue));
    pushptr = pushptr->next;
  }
  pushptr->next = NULL;
  pushptr->str = strdup(str);
  return 0;
}

/*was thinking of stacks
int push_queue(Queue **queue, char *str)
{
  Queue *newq = malloc(sizeof(Queue));
  newq->str = strdup(str);
  newq->next = *queue;
  *queue = newq;
}
*/
