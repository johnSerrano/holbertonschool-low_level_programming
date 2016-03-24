int str_len(char *str, int counter)
{
  if (*(str+counter) == 0) return counter;
  return str_len(str, counter+1);
}

int check_palindrome(char *s, int count, int len)
{
  if (count >= len) return 1;
  if (s[count] != s[(len-count)-1]) return 0;
  return check_palindrome(s, count+1, len);
}

int is_palindrome(char *s)
{
  int len = str_len(s, 0);
  return check_palindrome(s, 0, len);
}
