/*
 * Function that concatenates two strings, knowing length.
 */
char *str_ncat(char *dest, char *src, int len)
{
	char *ret = dest;
	while (*dest)
		dest++;
	while (len--) {
		if (!(*dest++ = *src++))
			return ret;
	}
	*dest = 0;
	return ret;
}

/*
 * Function that concatenates two strings without length.
 */
char *str_cat(char *dest, char *src)
{
	char *ret = dest;
	while (*dest != 0)
		dest++;
	while (*src != 0) {
		*dest = *src;
		src++;
		dest++;
	}
	*dest = 0;
	return ret;
}

/*
 * Function that copies a str into another.
 */
 char *string_copy(char *dest, const char *src)
{
	char *ret = dest;
	while (*src != 0) {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return(ret);
}
