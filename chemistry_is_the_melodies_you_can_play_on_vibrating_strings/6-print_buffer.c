#include <stdio.h>

int print_char(char);

void char_print_hex(char n) {
  int first = (int) ((n & 0xf0) >> 4);
  int second = (int) (n & 0x0f);
  if (first > 9) {
    print_char('a' + (first - 10));
  }
  else {
    print_char('0' + first);
  }
  if (second > 9) {
    print_char('a' + (second - 10));
  }
  else {
    print_char('0' + second);
  }
}

void print_int_hex(int n) {
  int mask;
  int n_copy = n, count = 0, i=0;
  int prints[4] = {0, 0, 0, 0};

  while (n_copy > 0) {
    n_copy /= 256;
    count++;
  }

  for ( ; count >= 0 ; count--) {
    mask=0xff;
    for (i=0 ; i<count ; i++) mask *= 0x100;
    prints[3 - count] = (n & mask);
    for (i=0; i<count; i++) prints[3-count] = (prints[3-count] >> 8);
  }
  for (i=0; i<4; i++) {
    char_print_hex((char) prints[i]);
  }
}

void print_buffer(char *b, int size) {
  int currpos = 0, currrow = 0;
  while (currpos < size) {
      print_int_hex(currrow * 10);
      do {
        if (currpos % 2 == 0) print_char(' ');
        if (currpos > size) {
          print_char(' ');
          print_char(' ');
        }
        else { char_print_hex(*(b + currpos)); }
        currpos++;
      } while (currpos % 10 != 0);
      print_char(' ');
      currpos = currrow * 10;
      do {
        if (*(b + currpos) > 31) print_char(*(b + currpos));
        else print_char('.');
        currpos++;
      } while (currpos % 10 != 0 && currpos < size);
      currrow++;
      print_char('\n');
  }
}
