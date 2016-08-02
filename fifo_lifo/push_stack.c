#include "stack.h"
#include <string.h>
#include <stdlib.h>

int push_stack(Stack **stack, char *str)
{
  Stack *news = (Stack *) malloc(sizeof(Stack));
  news->str = strdup(str);
  news->next = *stack;
  *stack = news;
  return 0;
}
