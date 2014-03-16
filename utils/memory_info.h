#include <string.h>
#include <stdlib.h>
#include <stdio.h>

namespace memory_info {
  /*
  enum VM_TYPE {    // virtual memory
    VM_RSS,         // resident set size.
    VM_SIZE,        // size. 
    VM_PEAK,        // peak virtual memory size.
    VM_HWM          // peak resident set size ("high water mark").
  };
  */

  unsigned parse_line(char* line);
  unsigned get_vmrss();
  unsigned get_vmsize();
  void print_full_info();
};
