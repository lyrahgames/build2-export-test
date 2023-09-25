#pragma once

#include <iosfwd>
#include <string>

#include <libmytest/export.hpp>

namespace mytest {

// Print a greeting for the specified name into the specified
// stream. Throw std::invalid_argument if the name is empty.
//
LIBMYTEST_SYMEXPORT
void say_hello(std::ostream&, const std::string& name);

// Print a goodbye message for the specified name into the specified
// stream. Throw std::invalid_argument if the name is empty.
//
void say_bye(std::ostream&, const std::string& name);

struct root {
  virtual void print(std::ostream&);
};

struct leaf : root {
  virtual ~leaf() noexcept = default;
  void print(std::ostream&) override;
};

}  // namespace mytest
