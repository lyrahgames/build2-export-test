#pragma once

namespace mytest {

struct wrapper {
  int data;
};

struct bug {
  bug(int value) noexcept;

  bug(const wrapper& value) noexcept : bug(value.data) {}

  virtual ~bug() noexcept = default;

  int data{};
};

}  // namespace mytest
