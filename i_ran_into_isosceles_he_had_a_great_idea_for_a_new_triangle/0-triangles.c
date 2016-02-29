#include <unistd.h>

int print_char(char);

void triangles_in_the_term(int h , int n)
{
	int i, space, height, width;
	for (i = 0; i < n; i++) {
		for (height = 0; height < h; height ++) {
			for (space = 0; space < (h - height); space++) {
				print_char(' ');
			}
			for (width = 0; width < (height * 2) + 1; width++) {
				print_char('*');
			}
		print_char('\n');
		}
	}
}

int print_char(char c)
{
  return (write(1, &c, 1));
}
