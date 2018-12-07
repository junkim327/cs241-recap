#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/dir.h>

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Usage: %s [directory]\n", *argv);
    exit(1);
  }

  struct dirent *dp;
  DIR *dirp = opendir(argv[1]);
  while ((dp = readdir(dirp)) != NULL) {
    printf("%s %lu\n", dp->d_name, (long) dp->d_ino);
  }

  closedir(dirp);

  return 0;
}