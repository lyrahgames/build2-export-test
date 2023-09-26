#include <memory>
#include <sstream>
#include <stdexcept>

#include <libmytest/mytest.hpp>
#include <libmytest/version.hpp>

#undef NDEBUG
#include <cassert>

int main() {
  using namespace std;
  using namespace mytest;

  // Basics.
  //
  {
    ostringstream o;
    say_hello(o, "World");
    assert(o.str() == "Hello, World!\n");
  }
  {
    ostringstream o;
    say_bye(o, "World");
    assert(o.str() == "Bye, World!\n");
  }

  // Empty name.
  //
  try {
    ostringstream o;
    say_hello(o, "");
    assert(false);
  } catch (const invalid_argument& e) {
    assert(e.what() == string("empty name"));
  }
  try {
    ostringstream o;
    say_bye(o, "");
    assert(false);
  } catch (const invalid_argument& e) {
    assert(e.what() == string("empty name"));
  }

  // Polymorphism Test
  //
  auto p = make_unique<root>(wrapper{1});
  {
    ostringstream o;
    p->print(o);
    assert(o.str() == "root 1\n");
  }
  // p = make_unique<leaf>(wrapper{2});
  // {
  //   ostringstream o;
  //   p->print(o);
  //   assert(o.str() == "leaf 2\n");
  // }
}
