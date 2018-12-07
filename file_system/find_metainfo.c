#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

/*
* Find out meta-information about a file
*/
int main() {
  struct stat s;
  stat("secret.txt", &s);
  printf("Last accessed %s", ctime(&s.st_atime));

  /*
  * You can use fstat to find out the meta-information about a file
  * if you already have an file descriptor associated with that file
  */
  FILE *file = fopen("secret.txt", "r");
  int fd = fileno(file);
  fstat(fd, &s);
  printf("Ownership: UID=%ld  GID=%ld\n", (long) s.st_uid, (long) s.st_gid);
  printf("File size: %lld bytes\n", (long long) s.st_size);

  printf("Las status change: %s", ctime(&s.st_ctime));
  printf("Last file access: %s", ctime(&s.st_atime));
  printf("Last file modification: %s", ctime(&s.st_mtime));

  return 0;
}