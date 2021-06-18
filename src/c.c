#include "../include/c.h"
#include <sys/stat.h>

void createCProject() {
  mkdir("src", 0777);
  mkdir("include", 0777);
}

