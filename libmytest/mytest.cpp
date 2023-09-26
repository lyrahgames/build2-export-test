#include <libmytest/mytest.hpp>

namespace mytest {

// Definition of non-inlined constructor in source file.
//
bug::bug(int value) noexcept : data{value} {}

}  // namespace mytest
