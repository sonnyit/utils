#include "memory_info.h"

namespace memory_info {
  unsigned parse_line(char* line) {
    unsigned length = strlen(line);
    while (*line < '0' || *line > '9')
      ++line;

    line[length - 3] = '\0';
    return atoi(line);
  }

  unsigned get_vmrss() {
    FILE* file = fopen("/proc/self/status", "r");
    unsigned result = 0;
    char line[128];
    
    while (fgets(line, 128, file) != NULL) {
      if (strncmp(line, "VmRSS:", 6) == 0) {
        result = parse_line(line);
        break;
      }
    }
    fclose(file);
    return result;
  }

  unsigned get_vmsize() {
    FILE* file = fopen("/proc/self/status", "r");
    unsigned result = 0;
    char line[128];
    
    while (fgets(line, 128, file) != NULL) {
      if (strncmp(line, "VmSize:", 7) == 0) {
        result = parse_line(line);
        break;
      }
    }
    fclose(file);
    return result;
  }

  void print_full_info() {
    FILE* file = fopen("/proc/self/status", "r");
    char line[128];
    
    while (fgets(line, 128, file) != NULL) {
      if (strncmp(line, "VmRSS:", 6) == 0) {
        printf("%s", line);
      }
      if (strncmp(line, "VmSize:", 7) == 0) {
        printf("%s", line);
      }
    }
    fclose(file);
  }
};
