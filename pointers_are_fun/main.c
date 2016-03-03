#include <stdio.h>
void reverse_string(char *s);
void print_string(char *str);
int str_len(char *str);
void swap_int(int *a, int *b);
void reset_to_98(int *n);

/*int string_to_integer(char *s);*/

int main(void)
{
  int n, a, b;
  char *str;
  int len;

  char s[10] = "Holberton";

  n = 402;
  printf("n=%d\n", n);
  reset_to_98(&n);
  printf("n=%d\n", n);

  a = 98;
  b = 42;
  printf("a=%d, b=%d\n", a, b);
  swap_int(&a, &b);
  printf("a=%d, b=%d\n", a, b);

  str = "Holberton!";
  len = str_len(str);
  printf("%d\n", len);

  str = "I do not fear computers. I fear the lack of them - Isaac Asimov\n";
  print_string(str);

  printf("%s\n", s);
  reverse_string(s);
  printf("%s\n", s);

  return (0);
}
