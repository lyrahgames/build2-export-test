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

template <typename type>
struct wrapper {
  type data;
};

template <typename type>
wrapper(const type&) -> wrapper<type>;

class root {
 public:
  root() noexcept = default;
  virtual ~root() noexcept = default;

  root(int value) noexcept;

  // template <typename type>
  // root(const wrapper<type>& value) noexcept : root(value.data) {}

  root(const wrapper<int>& value) noexcept : root(value.data) {}

  virtual void print(std::ostream&);

 protected:
  int data{};
};

// template <typename type>
// root::root(const wrapper<type>& value) noexcept : root(value.data) {}

// class leaf : public root {
//  public:
//   leaf() noexcept = default;
//   virtual ~leaf() noexcept = default;

//   leaf(int value) noexcept;

//   template <typename type>
//   leaf(const wrapper<type>& value) noexcept;

//   void print(std::ostream&) override;
// };

// template <typename type>
// leaf::leaf(const wrapper<type>& value) noexcept : leaf(value.data) {}

}  // namespace mytest
