#include <stdlib.h>
#include "list.h"

int print_char(char);
void print_str(char *str);

void print_dl_list(List *list) {
  char *i;
  while (list != NULL) {
    for (i = list->str ; *i!=0 ; i++) print_char(*i);
    print_char('\n');
    print_char('\t');
    if (list->prev != NULL) {
      for (i = list->prev->str ; *i!=0 ; i++) print_char(*i);
    } else {
      print_str("NULL");
    }
    print_char('\n');
    print_char('\t');
    if (list->next != NULL) {
      for (i = list->next->str ; *i!=0 ; i++) print_char(*i);
    } else {
      print_str("NULL");
    }
    print_char('\n');
    list = list->next;
  }
}

void print_str(char *str) {
  for ( ; *str != 0 ; str++) print_char(*str);
}
