#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int print_as_single_args(char *, int);
int used(char **, char *);

/*TODO check used_args*/

int main(int argc, char **argv)
{
  char **used_args;
  int i;
  int first = 1;
  char *argptr;
  used_args = malloc(sizeof(char *));
  used_args[0] = "";
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "--") == 0) break;
    argptr = argv[i];
    if (used(argv, argptr) == 1) continue;
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (first != 1)
          printf(", ");
        else
          first = 0;
        argptr = argv[i];
        argptr++;
        argptr++;
        printf("%s", argptr);
      }
      else {
        argptr = argv[i];
        argptr++;
        first = print_as_single_args(argptr, first);
      }
    }
  }
  printf("\n");
  return 0;
}

int used(char **argv, char *arg) {
  argv++;
  arg++;
  return 0;
}

int print_as_single_args(char *s, int first) {
  while (*s != 0) {
    if (first != 1)
      printf(", ");
    else
      first = 0;
    printf("%c", *s);
    s++;
  }
  return first;
}
