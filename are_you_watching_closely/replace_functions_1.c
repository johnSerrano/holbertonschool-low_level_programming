#include <stdarg.h>
#include <stdlib.h>

char *int_to_string(int n, unsigned int base);
char *unsigned_to_string(unsigned int n, unsigned int base);
char *replace_string(char *base, char *directive, char *toreplace);

/* function for d and i (int replacement) */
char *replace_d(char *base, char *directive, va_list ap) {
	int val = va_arg(ap, int);
	char *str = int_to_string(val, 10);
	char *ret;
	/* int to str, then replace_string() */
	ret = replace_string(base, directive, str);
	free(str);
	return ret;
}

/* function for u (unsigned int to decimal) */
char *replace_u(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 10);
	char *ret;
	/* unsigned int to str, then replace_string() */
	ret = replace_string(base, directive, str);
	free (str);
	return ret;
}

/* function for o (unsigned int to octal) */
char *replace_o(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 8);
	char *ret;
	ret = replace_string(base, directive, str);
	free(str);
	return ret;
}

/* function for lower case hex substitution (unsigned int) */
char *replace_x(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 16);
	char *ret;
	ret = replace_string(base, directive, str);
	free (str);
	return ret;
}

/* function for upper case hex substitution (unsigned int) */
char *replace_X(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 16);
	char *iter;
	for (iter = str; *iter != 0; iter++) {
		if (*iter >= 'a' && *iter <= 'z') *iter += ('A' - 'a');
	}
	iter = replace_string(base, directive, str);
	free(str);
	return iter;
}
