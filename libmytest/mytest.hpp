#pragma once

namespace mytest {

struct wrapper {
  int data;
};

struct root {
  root(int value) noexcept;

  root(const wrapper& value) noexcept : root(value.data) {}

  // virtual ~root() noexcept = default;

  int data{};
};

}  // namespace mytest
