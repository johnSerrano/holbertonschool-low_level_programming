#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void read_stdin();
int print_file(char *filename);
int len(char *str);

/* Cat clone */
int main(int argc, char **argv) {
  int i;
  if (argc < 2) {
    read_stdin();
    return 0;
  }
  for (i=1 ; i<argc ; i++) {
    print_file(argv[i]);
  }
  return 0;
}

/* print whatever comes into stdin */
void read_stdin() {
  char ch;
  while(read(0, &ch, 1) > 0)
  {
    write(1, &ch, 1);
  }
}

/* Print the contents of a file */
int print_file(char *filename) {
  char *buffer;
  int file;
  struct stat fileStat;
  int size;

  file = open(filename, O_RDONLY);
  if (file == -1) {
    write(1, "cat: ", 5);
    write(1, filename, len(filename));
    write(1, ": No such file or directory", 27);
    return 1;
  }

  if (stat(filename, &fileStat) < 0) return 1;

  size = fileStat.st_size;
  buffer = malloc(size);

  read(file, buffer, size);
  write(1, buffer, size);

  close(file);

  return 0;
}

/* string length, not counting null terminator */
int len(char *str) {
  int length = 0;
  while (*str != 0) {
    length++;
    str++;
  }
  return length;
}
