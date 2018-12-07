#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/dir.h>

/*
* Check whether the file exists in the directory.
*/
int exists(char *directory, char *file_name) {
  struct dirent *dp;
  DIR *dirp = opendir(directory);
  printf("File list: \n");
  while ((dp = readdir(dirp)) != NULL) {
    puts(dp->d_name);
    if (!strcmp(dp->d_name, file_name)) {
      closedir(dirp);
      return 1;
    }
  }

  closedir(dirp);
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s [directory] [file name]\n", *argv);
    exit(1);
  } 

  char *directory = argv[1];
  char *file_name = argv[2];

  int result = exists(directory, file_name);
  if (result == 1) {
    printf("\n%s is in the %s\n", file_name, directory);
  } else {
    printf("\nFailed to find %s\n", file_name);
  }

  return 0;
}