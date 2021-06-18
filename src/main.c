#include <stdio.h>
#include <string.h>
#include "../include/c.h"

int main(int argc, char **argv) {
  char *language;
  char *path;
  if (argc < 3) {
    fprintf(stderr, "Invalid arguments");

    return 1;
  }

  language = argv[1];
  path = argv[2];

  if (!strcmp(language, "c")) {
    createCProject(path);
  }

  return 0;
}

