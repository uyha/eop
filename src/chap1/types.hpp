//
// Created by uyha on 6/20/2020.
//

#pragma once

namespace eop {
struct Regular {};
bool operator==(Regular, Regular) {
  return true;
}
bool operator!=(Regular, Regular) {
  return false;
}
bool operator<(Regular, Regular) {
  return false;
}
bool operator>(Regular, Regular) {
  return false;
}
bool operator<=(Regular, Regular) {
  return false;
}
bool operator>=(Regular, Regular) {
  return false;
}
} // namespace eop