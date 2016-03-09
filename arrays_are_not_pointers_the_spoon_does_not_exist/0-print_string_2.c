int print_char(char);

void print_string_2(char *str)
{
  int count = 0;
  while (*(str+count) != 0) {
    if (count % 2 == 0) {
      print_char(*(str+count));
    }
    count++;
  }
}
