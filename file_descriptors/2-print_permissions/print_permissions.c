#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  struct stat fileStat;

  if (argc != 2) return 1;
  if (lstat(argv[1], &fileStat) < 0) return 1;

  write(1, (S_ISDIR(fileStat.st_mode)) ? "d" :
            (S_ISLNK(fileStat.st_mode)) ? "l" : "-", 1);
  write(1, (fileStat.st_mode & S_IRUSR) ? "r" : "-", 1);
  write(1, (fileStat.st_mode & S_IWUSR) ? "w" : "-", 1);
  write(1, (fileStat.st_mode & S_IXUSR) ? "x" : "-", 1);
  write(1, (fileStat.st_mode & S_IRGRP) ? "r" : "-", 1);
  write(1, (fileStat.st_mode & S_IWGRP) ? "w" : "-", 1);
  write(1, (fileStat.st_mode & S_IXGRP) ? "x" : "-", 1);
  write(1, (fileStat.st_mode & S_IROTH) ? "r" : "-", 1);
  write(1, (fileStat.st_mode & S_IWOTH) ? "w" : "-", 1);
  write(1, (fileStat.st_mode & S_IXOTH) ? "x" : "-", 1);
  write(1, "\n", 1);

  return 0;
}
