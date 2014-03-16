#include "utils/time_execute_info.h"
#include "utils/memory_info.h"
#include "utils/custom_struct.h"
#include <unistd.h>
#include <map>
#include <iostream>

int main() {
  using namespace std;
  using namespace time_execute_info;
  using namespace memory_info;
 

  typedef Custom_Struct<int> Key;
  map<Key, int> map1;
  map<int, int> map2;

  cout << "vmrss: " << get_vmrss() << " KB" << endl;
  set_time_point_manual("p1");
  
  for (int i = 0; i < 10000000; ++i) {
    map1[Key(i)] = i;
  }

  cout << "done p1 in: " << get_time_pass_manual("p1", MILLISECONDS) << " millisecond" << endl;
  cout << "vmrss of p1: " << get_vmrss() << " KB" << endl;

  set_time_point_auto();
  for (int i = 0; i < 10000000; ++i) {
    map2[i] = i;
  }

  cout << "done p2 in: " << get_time_pass_auto(MILLISECONDS) << " millisecond" << endl;
  cout << "vmrss of p2: " << get_vmrss() << " KB" << endl;
}
