#include "../include/python.h"
#include <stdlib.h>
#include <string.h>

void createPythonProject(const PythonOptions *options) {
  char *createVenvCommand = malloc(sizeof(char) * (15 + strlen(options->venvName) + 1)); // 15 is the length of "python -m venv "

  if (options->useVenv) {
    strcpy(createVenvCommand, "python -m venv ");
    strcat(createVenvCommand, options->venvName);
    system("python -m venv venv");
  }

  free(createVenvCommand);
}

