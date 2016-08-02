#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* The function 'print_stack' is provided */
void print_stack(const Stack *);

int push_stack(Stack **, char *);

int main(int ac, char **av)
{
        Stack *stack;
        int i;
        char *str;

        stack = NULL;
        i = 0;
        while (i < ac)
        {
                push_stack(&stack, av[i]);
                ++i;
        }
        print_stack(stack);
        return (0);
}

void print_stack(const Stack *s)
{
  while (s != NULL) {
    printf("%s\n", s->str);
    s = s->next;
  }
}
