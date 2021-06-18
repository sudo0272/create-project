#include "../include/c.h"
#include <unistd.h>
#include <sys/stat.h>

void createCProject(char *path) {
  chdir(path);

  mkdir("src", 0777);
  mkdir("include", 0777);
}

