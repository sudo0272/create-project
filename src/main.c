#include "../include/c.h"
#include "../include/git.h"
#include "../include/help.h"
#include "../include/python.h"
#include <getopt.h>
#include <limits.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
  char *language;
  char *path = (char *)malloc(sizeof(char) * PATH_MAX);
  char *name;
  COptions cOptions;
  PythonOptions pythonOptions;
  GitOptions gitOptions;
  int useGit;
  int option_index = 0;
  int current_option;

  struct option longOptions[] = {
      {"git", no_argument, &useGit, 1},
      {"nogit", no_argument, &useGit, 0},
      {"venv", no_argument, &pythonOptions.useVenv, 1},
      {"novenv", no_argument, &pythonOptions.useVenv, 0},
      {"venv-name", required_argument, NULL, 'v'},
      {"help", no_argument, NULL, 'h'},
      {0, 0, 0, 0}};

  // initialize options to default
  pythonOptions.useVenv = 1;
  pythonOptions.venvName = NULL;

  while (1) {
    current_option = getopt_long(argc, argv, "h", longOptions, &option_index);

    if (current_option == -1) {
      break;
    }

    switch (current_option) {
    case 0:
      break;

    case 'h':
      printHelp();

      return 0;

    case '?':
      break;

    default:
      abort();
    }
  }

  if (optind + 2 != argc) {
    printHelp();

    return 1;
  }

  realpath(argv[optind++], path);
  name = strrchr(path, '/');
  *name = '\0';
  name++;
  language = argv[optind];

  chdir(path);
  mkdir(name, 0777);
  chdir(name);

  if (!strcmp(language, "c")) {
    createCProject(&cOptions);
  } else if (!strcmp(language, "python")) {
    createPythonProject(&pythonOptions);
  }

  if (useGit) {
    initGit(&gitOptions);
  }

  free(path);

  return 0;
}
