#include <libmytest/mytest.hpp>

namespace mytest {

bug::bug(int value) noexcept : data{value} {}

void bug2::set(int value) noexcept {
  data = value;
}

}  // namespace mytest
