#pragma once

#include <chrono>
#include <ctime>

class Invitation {
 private:
  std::time_t when;

 public:
  Invitation() {
    auto now = std::chrono::system_clock::now();
    when = std::chrono::system_clock::to_time_t(now);
  }
  Invitation(std::time_t when) : when(when) {}
};