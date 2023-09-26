#include <memory>
//
#include <libmytest/mytest.hpp>
//
#undef NDEBUG
#include <cassert>

using namespace std;
using namespace mytest;

int main() {
  // auto p = make_unique<root>(wrapper{1});
  // assert(p->data == 1);

  root x{wrapper{1}};
  assert(x.data == 1);
}
