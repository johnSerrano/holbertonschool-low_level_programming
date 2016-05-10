#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int file;
  int size;
  int new_file;
  char *buffer;
  struct stat fileStat;
  if (argc != 3) return 1;
  file = open(argv[1], O_RDONLY);
  new_file = open(argv[2], O_WRONLY | O_CREAT);
  if (file == -1 || new_file == -1) return 1;
  chmod(argv[2], S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
  if (stat(argv[1], &fileStat) < 0) return 1;
  size = fileStat.st_size;
  buffer = malloc(size);
  read(file, buffer, size);
  write(new_file, buffer, size);
  close(new_file);
  free(buffer);
  close(file);
  return 0;
}
