int find_prime(int n, int count) {
  if (n <= 1) return 0;
  if (count > n/2) return 1;
  if (n % count == 0) return 0;
  return find_prime(n, count+1);
}

int is_prime_number(int n)
{
  return find_prime(n, 2);
}
