#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* note to self: skip %% and others?
   can't restart after substitution, keep count? */
int printa(const char *format, ...);
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

int main(void) {
	char a;
	printa("s: %s\nd: %d\nu: %u\no: %o\nx: %x\nX: %X\nc: %c\np: %p\n%%: %%\n", "st", 100, 98u, 65, 60, 60, 'a', &a);
	printf("s: %s\nd: %d\nu: %u\no: %o\nx: %x\nX: %X\nc: %c\np: %p\n%%: %%\n", "st", 100, 98u, 65, 60, 60, 'a', &a);
	return 0;
}

int printa(const char *format, ...) {
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
	/* TODO return number of bytes printed (strlen) */
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
	char *str;
	for (i=0 ; i<10 ; i++) {
		if (relations[i].directive == *(directive+1)) {
			str = relations[i].replace(base, directive, ap);
		}
	}
	return str;
}

char *replace_s(char *base, char* directive, va_list ap) {
	char *toreplace = va_arg(ap, char *);
	return replace_string(base, directive, toreplace);
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
	/* TODO free base */
	return str;
}

/* function for d and i (int replacement) */
char *replace_d(char *base, char *directive, va_list ap) {
	int val = va_arg(ap, int);
	char *str = int_to_string(val, 10);
	/* int to str, then replace_string() */
	return replace_string(base, directive, str);
}

/* function for u (unsigned int to decimal) */
char *replace_u(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 10);
	/* unsigned int to str, then replace_string() */
	return replace_string(base, directive, str);
}

/* function for o (unsigned int to octal) */
char *replace_o(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 8);
	return replace_string(base, directive, str);
}

/* function for lower case hex substitution (unsigned int) */
char *replace_x(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 16);
	return replace_string(base, directive, str);
}

/* function for upper case hex substitution (unsigned int) */
char *replace_X(char *base, char *directive, va_list ap) {
	unsigned int val = va_arg(ap, unsigned int);
	char *str = unsigned_to_string(val, 16);
	char *iter;
	for (iter = str; *iter != 0; iter++) {
		if (*iter >= 'a' && *iter <= 'z') *iter += ('A' - 'a');
	}
	return replace_string(base, directive, str);
}

/* function for character substitution */
char *replace_c(char *base, char *directive, va_list ap) {
	char a = (char)va_arg(ap, int);
	char * str = malloc(sizeof(char) * 2);
	*str = a;
	*(str+1) = 0;
	return replace_string(base, directive, str);
}

/* ASSUMES 64 BIT SYSTEM */
/* this is more complicated than necessary because I didn't want to write
 * a new int to str for longs
 */
char *replace_p(char *base, char *directive, va_list ap) {
	void *ptr = va_arg(ap, void *);
	unsigned int ptr1 =
		(unsigned int)((unsigned long)ptr & 0xfffffffful);
	/* division not bitshift because I'm incompetent today*/
	unsigned int ptr2 = (unsigned int)
		(((unsigned long)ptr & 0xffffffff00000000ul)/0x100000000);
	char *str1 = unsigned_to_string(ptr1, 16);
	char *str2 = unsigned_to_string(ptr2, 16);
	char *str = malloc(sizeof(char) * 19);
	*str = '0';
	*(str+1) = 'x';
	*(str+2) = 0;
	str_cat(str, str2);
	str_cat(str, str1);
	return replace_string(base, directive, str);
}

/* function for escaped percent substitution */
char *replace_percent(char *base, char *directive,
	__attribute__((unused)) va_list ap) {
	char a = '%';
	char * str = malloc(sizeof(char) * 2);
	*str = a;
	*(str+1) = 0;
	return replace_string(base, directive, str);
}
