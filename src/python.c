#include "../include/python.h"
#include <stdlib.h>
#include <string.h>

void createPythonProject(const PythonOptions *options) {
  char *createVenvCommand = malloc(
      sizeof(char) *
      (15 + (options->venvName ? strlen(options->venvName) : 4) +
       1)); // 15 is the length of "python -m venv ", 4 is the length of "venv"

  if (options->useVenv) {
    strcpy(createVenvCommand, "python -m venv ");
    strcat(createVenvCommand, options->venvName ? options->venvName : "venv");
    system(createVenvCommand);
  }

  free(createVenvCommand);
}
