#include "../include/git.h"
#include <stdlib.h>
#include <unistd.h>

void initGit(char *path) {
  chdir(path);
  system("git init");
}

