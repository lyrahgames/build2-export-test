#include <libmytest/mytest.hpp>
//
#undef NDEBUG
#include <cassert>

using namespace mytest;

int main() {
  root x{wrapper{1}};
  assert(x.data == 1);
}
