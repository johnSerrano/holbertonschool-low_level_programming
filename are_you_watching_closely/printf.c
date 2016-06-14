#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int printf(const char *format, ...);
int str_len(const char *str);
char *int_to_string(int n, unsigned int base);
char *unsigned_to_string(unsigned int n, unsigned int base);
char *string_copy(char *dest, const char *src);
char *str_ncat(char *dest, char *src, int len);
char *str_cat(char *dest, char *src);
char *replace(char *base, char *directive, va_list ap);
char *replace_string(char *base, char *directive, char *toreplace);
char *replace_s(char *base, char *directive, va_list ap);
char *replace_d(char *base, char *directive, va_list ap);
char *replace_u(char *base, char *directive, va_list ap);
char *replace_o(char *base, char *directive, va_list ap);
char *replace_x(char *base, char *directive, va_list ap);
char *replace_X(char *base, char *directive, va_list ap);
char *replace_c(char *base, char *directive, va_list ap);
char *replace_p(char *base, char *directive, va_list ap);
char *replace_percent(char *base, char *directive, va_list ap);

int printf(const char *format, ...) {
	/* LOOP OVER FORMAT */
	va_list ap;
	int count = 0;
	char *mut = malloc(sizeof(char) * (	str_len(format) + 1));
	char *pointer = mut;
	string_copy(mut, format);

	va_start(ap, format);
	while (*pointer != 0) {
		if (*pointer == '%') {
			/* TODO (no vararg value is 0 or null) */
			count = pointer - mut;
			mut = replace(mut, pointer, ap);
			pointer = mut + count;
		}
		pointer++;
	}
	count = str_len(mut);
	write(1, mut, count);
	free(mut);
	va_end(ap);
	return count;
}

char *replace(char *base, char *directive, va_list ap) {
	struct replace_relation {
		char directive;
		char *(*replace)(char *, char *, va_list);
	};
	/* array of directive to function structs */
	struct replace_relation relations[10] = {
		{'d', replace_d},
		{'i', replace_d},
		{'u', replace_u},
		{'o', replace_o},
		{'x', replace_x},
		{'X', replace_X},
		{'c', replace_c},
		{'s', replace_s},
		{'p', replace_p},
		{'%', replace_percent}
	};
	int i;
	char *str = base;
	for (i=0 ; i<10 ; i++) {
		if (relations[i].directive == *(directive+1)) {
			str = relations[i].replace(base, directive, ap);
			break;
		}
	}
	return str;
}

/* replace a string */
char *replace_string(char *base, char *directive, char *toreplace) {
	char *str = directive + 1;
	int len1 = directive - base;
	int len2 = 0;
	int len3 = 0;
	while (*str != 0) {
		len2++;
		str++; }
	str = toreplace;
	while (*str != 0) {
		len3++;
		str++; }
	str = malloc(sizeof(char) * (len1 + len2 + len3) + 1);
	*str = 0;
	str_ncat(str, base, len1);
	str_cat(str, toreplace);
	str_cat(str, (directive + 2));
	free(base);
	return str;
}
