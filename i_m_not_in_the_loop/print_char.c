#include <unistd.h>
#include "my_functions.h"
#include <errno.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

int print_string(char *to_print)
{
	/*
	 * prints a null terminated string to stdout.
	 * returns 0 if successful, otherwise returns exit status of write.
	 */
	char *current_char = to_print;
	errno = 0;
	while (*current_char != 0) {
		int exit_status_of_write = print_char(*current_char);
		if (errno != 0) {
			return exit_status_of_write;
		}
		current_char += 1;
	}
	return 0;
}
