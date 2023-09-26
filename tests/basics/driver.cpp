#include <libmytest/mytest.hpp>
//
#undef NDEBUG
#include <cassert>

using namespace mytest;

int main() {
  // Calling this constructor leads to an error in MSVC
  // when used with autmatic DLL symbol exportation.
  //
  // error LNK2019: unresolved external symbol "const mytest::bug::`vftable'"
  // referenced in function "public: __cdecl mytest::bug::bug(struct mytest::wrapper const &)"
  //
  bug x{wrapper{1}};
  assert(x.data == 1);
}
