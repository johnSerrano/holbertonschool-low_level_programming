int find_root(int n, int count) {
  if (count * count == n) return count;
  if (count * count > n) return -1;
  return find_root(n, count+1);
}

int square_root(int n) {
  return find_root(n, 1);
}
