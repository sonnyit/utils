#include <chrono>
#include <stack>
#include <map>
#include <string>

namespace time_execute_info {
  static std::stack<std::chrono::steady_clock::time_point> stack_time_point;
  static std::map<std::string, std::chrono::steady_clock::time_point> map_time_point;
  
  enum TimeUnit {
    SECONDS,
    MILLISECONDS,
    MICROSECONDS
  };

  void set_time_point_auto() {
    stack_time_point.push(std::chrono::steady_clock::now());
  }

  void set_time_point_manual(std::string title) {
    map_time_point[title] = std::chrono::steady_clock::now();
  }

  double get_time_pass_auto(TimeUnit time_unit = SECONDS) {
    std::chrono::steady_clock::time_point time_point;
    if (stack_time_point.size() > 0) {
      time_point = stack_time_point.top();
      stack_time_point.pop();
    } else {
      return -1;
    }

    if (time_unit == MICROSECONDS) {
      return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    if (time_unit == SECONDS) {
      return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    if (time_unit == MILLISECONDS) {
      return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    return -1;
  }

  double get_time_pass_manual(std::string title, TimeUnit time_unit = SECONDS) {
    std::chrono::steady_clock::time_point time_point;
    if (map_time_point.find(title) != map_time_point.end()) {
      time_point = map_time_point[title]; 
    } else {
      return -1;
    }

    if (time_unit == MICROSECONDS) {
      return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    if (time_unit == SECONDS) {
      return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    if (time_unit == MILLISECONDS) {
      return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - time_point).count();
    }

    return -1;
  }

};
