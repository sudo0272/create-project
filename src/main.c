#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include "../include/c.h"
#include "../include/git.h"
#include "../include/python.h"

int main(int argc, char **argv) {
  char *language;
  char *path = (char *) malloc(sizeof(char) * PATH_MAX);
  char *projectName;

  if (argc < 4) {
    fprintf(stderr, "Invalid arguments");

    return 1;
  }

  projectName = argv[1];
  language = argv[2];
  realpath(argv[3], path);

  chdir(path);
  mkdir(projectName, 0777);
  chdir(projectName);

  if (!strcmp(language, "c")) {
    createCProject();
  } else if (!strcmp(language, "python")) {
    createPythonProject();
  }

  initGit();

  free(path);

  return 0;
}

