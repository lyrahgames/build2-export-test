#pragma once

namespace mytest {

struct wrapper {
  int data;
};

struct root {
  root() noexcept = default;
  virtual ~root() noexcept = default;

  root(int value) noexcept;

  // template <typename type>
  // root(const wrapper<type>& value) noexcept : root(value.data) {}

  root(const wrapper& value) noexcept : root(value.data) {}

  // virtual void print(std::ostream&);

  int data{};
};

}  // namespace mytest
