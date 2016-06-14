#include <stdarg.h>
#include <stdlib.h>

char *unsigned_to_string(unsigned int n, unsigned int base);
char *str_cat(char *dest, char *src);
char *replace_string(char *base, char *directive, char *toreplace);

/* function to replace a string (va_args compatibility)*/
char *replace_s(char *base, char* directive, va_list ap) {
	char *toreplace = va_arg(ap, char *);
	return replace_string(base, directive, toreplace);
}

/* function for character substitution */
char *replace_c(char *base, char *directive, va_list ap) {
	char a = (char)va_arg(ap, int);
	char * str = malloc(sizeof(char) * 2);
	char *ret;
	*str = a;
	*(str+1) = 0;
	ret = replace_string(base, directive, str);
	free(str);
	return ret;
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
	free(str1);
	free(str2);
	str1 = replace_string(base, directive, str);
	free(str);
	return str1;
}

/* function for escaped percent substitution */
char *replace_percent(char *base, char *directive,
	__attribute__((unused)) va_list ap) {
	char a = '%';
	char * str = malloc(sizeof(char) * 2);
	char *ret;
	*str = a;
	*(str+1) = 0;
	ret = replace_string(base, directive, str);
	free(str);
	return ret;
}
