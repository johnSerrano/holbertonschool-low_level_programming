#include <stdarg.h>
#include <stdlib.h>
/* TODO look into VA headers, va start, va_list, etc... */
/* note to self: int to str can take base as a parameter easily */
/* note to self: handle size issues first, then treat everything as ll
 *		 where applicable.
 */
/* note to self: how to deal with escaped chars reasonably? need good algo */
/* note to self: handling long longs with ancient c standard? Printf
 * behavior is to not compile...
 */
/* going to be so much debugging ... */

/* struct to map directives to functions */

char *int_to_string(long long n, int base);

struct replace_relation {
	char directive;
	char *(*replace)(char *, char *, char *, void *);
}

/* array of directive to function structs */
struct replace_relation relations[10] = {
	{'d', replace_d},
	{'i', replace_d},
	{'u', replace_u},
	{'o', replace_o},
	{'x', replace_x},
	{'X', replace_X},
	{'c', replace_c},
	{'s', replace_string},
	{'p', replace_p},
	{'%', replace_percent}
};


int printf(const char *format, ...) {
	/* LOOP OVER FORMAT */
	while (*format != 0) {
		/* TODO when directive is found, call replace function */
		if (*format == '%') {
			/* TODO find end of directive */
			/* TODO call replace with directive as a string*/
			/* TODO varargs for values (no value is 0 or null) */
			/* TODO value mismatch? */
		}
	}
	/* print string */
	/* TODO return number of bytes printed */
	return 0;
}

/* TODO generic replace function */
char *replace(char *base, char *substitution_start,
		char *substitution_end, void *replacement) {
	/* sub_start and sub_end wrap directive */
	/* TODO process directive (so specific!) */
	/* TODO length modifiers
	 * consult http://www.wpollock.com/CPlus/PrintfRef.htm
	 * hh: everything is char sized (signed or unsigned?)
	 * h: same, except short
	 * l: same except long with some exceptions
	 * ll: arg is long long. we have to use c1000BC. gl
	 */
	/* TODO use relations to find the correct function for directive and
	 * exec
	 */
}

/* TODO replacement function for two strings. all other functions need only
   generate a string and call this function */
char *replace_string(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TODO cast void *replacement as char * */
	/* TODO replace base between sub_start and sub_end with replacement*/
	/* TODO find length of base to s_start, s_end to null, and replacement
	   & malloc */
	/* TODO copy base to s_start, replace, then s_end to null */
	/* TODO free base */
	/* TODO return new string */
}

/* function for d and i (int replacement) */
char *replace_d(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* cast void *replacement as int * */
	long long *replacement_int_p = (long long *)replacement;
	long long val = *replacement_int_p;
	char *str = int_to_string((long long)val, 10);
	/* int to str, then replace_string() */
	return replace_string(base,substitution_start,substitution_end,str);
}

/* function for u (unsigned int to decimal) */
char *replace_u(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* cast void *replacement as unsigned int * */
	unsigned long long *replacement_int_p = (unsigned long long *)replacement;
	unsigned long long val = *replacement_int_p;
	char *str = int_to_string((long long)val, 10);

	/* unsigned int to str, then replace_string() */
	return replace_string(base,substitution_start,substitution_end,str);
}

/* TODO function for o (unsigned int to octal) */
char *replace_o(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TODO cast void *replacement as unsigned int * */
	/* TODO unsigned int to octal str, then replace_string() */
}

/* TODO function for lower case hex substitution (unsigned int) */
char *replace_x(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TODO cast void *replacement as unsigned int * */
 	/* TODO unsigned int to hex str, then replace_string() */
}

/* TODO function for upper case hex substitution (unsigned int) */
char *replace_X(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TODO cast void *replacement as unsigned int * */
 	/* TODO unsigned int to hex str, then replace_string() */
}

/* TODO function for character substitution */
char *replace_c(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TODO cast void *replacement as char * */
 	/* TODO char to str, then replace_string() */
}

/* TODO function for void substitution */
char *replace_p(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* no need to cast */
 	/* TODO fixed-width upper case hex */
}

/* TODO function for no substitution */
char *replace_percent(char *base, char *substitution_start,
		     char *substitution_end, void *replacement) {
	/* TONOTDO don't handle void *replacement, need for compatibility*/
 	/* TODO replace directive  with '%' */
}
