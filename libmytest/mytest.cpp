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

}  // namespace mytest
