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
  char *name;

  if (argc < 3) {
    fprintf(stderr, "Invalid arguments\n");

    return 1;
  }

  realpath(argv[1], path);
  name = strrchr(path, '/');
  *name = '\0';
  name ++;
  language = argv[2];

  chdir(path);
  mkdir(name, 0777);
  chdir(name);

  if (!strcmp(language, "c")) {
    createCProject();
  } else if (!strcmp(language, "python")) {
    createPythonProject();
  }

  initGit();

  free(path);

  return 0;
}

