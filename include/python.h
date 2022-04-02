#pragma once

typedef struct {
  int useVenv;
  char *venvName;
} PythonOptions;

void createPythonProject(const PythonOptions *);
