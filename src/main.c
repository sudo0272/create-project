#include <stdio.h>
#include <string.h>
#include "../include/c.h"
#include "../include/git.h"
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
  char *language;
  char *path;
  char *projectName;

  if (argc < 3) {
    fprintf(stderr, "Invalid arguments");

    return 1;
  }

  projectName = argv[1];
  path = argv[2];
  language = argv[3];

  chdir(path);
  mkdir(projectName, 0777);
  chdir(projectName);

  if (!strcmp(language, "c")) {
    createCProject();
  }

  initGit();

  return 0;
}

