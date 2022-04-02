#include "../include/c.h"
#include <sys/stat.h>

void createCProject(const COptions *options) {
  mkdir("src", 0777);
  mkdir("include", 0777);
}
