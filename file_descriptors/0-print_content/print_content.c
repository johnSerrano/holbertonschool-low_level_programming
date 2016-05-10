#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  char *buffer;
  int file;
  struct stat fileStat;
  int size;

  if (argc != 2) return 1;
  file = open(argv[1], O_RDONLY);
  if (file == -1) return 1;

  if (stat(argv[1], &fileStat) < 0) return 1;

  size = fileStat.st_size;
  buffer = malloc(size);

  read(file, buffer, size);
  write(1, buffer, size);

  close(file);

  return 0;
}
