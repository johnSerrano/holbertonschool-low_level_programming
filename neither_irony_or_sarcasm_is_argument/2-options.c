#include <stdio.h>
#include <string.h>

int print_as_single_args(char *, int, char **, int);
int check_string_args(int, char **, char *);

int main(int argc, char **argv)
{
  int i;
  int first = 1;
  char *argptr;
  for (i=1; i<argc; i++) {
    argptr = argv[i];
    if (strcmp(argv[i], "--") == 0) break;
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (check_string_args(argc, argv, argptr) == 1) continue;
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
        first = print_as_single_args(argptr, first, argv, argc);
      }
    }
  }
  printf("\n");
  return 0;
}

int check_string_args(int argc, char **argv, char *to_check)
{
  int i;
  char *argptr;
  for (i=1; i<argc; i++) {
    argptr = argv[i];
    if (argptr == to_check) break;
    if (strcmp(argv[i], "--") == 0) break;
    if (argv[i][0] == '-') {
      if (argv[i][1] == '-') {
        if (strcmp(argptr, to_check) == 0) return 1;
      }
    }
  }
  return 0;
}

int check_single_args(int argc, char **argv, char *to_check)
{
  int i;
  char *argptr;
  for (i=1; i<argc; i++) {
    argptr = argv[i];
    if (argptr == to_check) break;
    if (strcmp(argv[i], "--") == 0) break;
    if (argv[i][0] == '-') {
      if (argv[i][1] != '-')
        while (*argptr != 0) {
          if (argptr == to_check) return 0;
          if(*to_check == *argptr) return 1;
          argptr++;
      }
    }
  }
  return 0;
}

int print_as_single_args(char *s, int first, char **argv, int argc) {
  while (*s != 0) {
    if (check_single_args(argc, argv, s) != 0) {
      s++;
      continue;
    }
    if (first != 1)
      printf(", ");
    else
      first = 0;
    printf("%c", *s);
    s++;
  }
  return first;
}
