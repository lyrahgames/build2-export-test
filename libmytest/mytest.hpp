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
  root() noexcept = default;
  virtual ~root() noexcept = default;

  template <typename type>
  root(type value) noexcept {}

  virtual void print(std::ostream&);
};

struct leaf : root {
  leaf() noexcept = default;
  virtual ~leaf() noexcept = default;

  template <typename type>
  leaf(type value) noexcept : root(value) {}

  void print(std::ostream&) override;
};

}  // namespace mytest
