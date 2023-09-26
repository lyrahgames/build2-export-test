#include <libmytest/mytest.hpp>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace mytest {

void say_hello(ostream& o, const string& n) {
  if (n.empty()) throw invalid_argument("empty name");

  o << "Hello, " << n << '!' << endl;
}

void say_bye(ostream& o, const string& n) {
  if (n.empty()) throw invalid_argument("empty name");

  o << "Bye, " << n << '!' << endl;
}

root::root(int value) noexcept : data{value} {}

// void root::print(ostream& o) {
//   o << "root " << data << endl;
// }

// leaf::leaf(int value) noexcept : root(value) {}

// void leaf::print(ostream& o) {
//   o << "leaf " << data << endl;
// }

}  // namespace mytest
