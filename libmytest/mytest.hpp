#pragma once

namespace mytest {

// 'int'-Wrapping Structure
//
// It is used to make an explicit alternative constructor available.
// This structure could also be a template for example.
//
struct wrapper {
  int data;
};

// Using automatic DLL symbol exportation in MSVC,
// this struct emits the following error
// when its inlined constructor is called.
//
// error LNK2019: unresolved external symbol "const mytest::bug::`vftable'"
// referenced in function "public: __cdecl mytest::bug::bug(struct mytest::wrapper const &)"
//
struct bug {
  // Virtual Default Destructor
  //
  // Marking the destructor as virtual makes sure that MSVC generates
  // the virtual function table 'vftable' for every object of that class.
  // Alternatively, the same behavior could be achieved
  // by marking any other member function as virtual.
  //
  virtual ~bug() noexcept = default;

  // Constructor Declaration
  //
  // Its implementation must be given in the source file.
  //
  bug(int value) noexcept;

  // Alternative Inlined Constructor Definition
  //
  // It must call the first not inlined constructor.
  // In particular, this may happen for constructor templates.
  // These would either need to be inlined or provided
  // by an inclusion file. Both methods lead to an error.
  //
  bug(const wrapper& value) noexcept : bug(value.data) {}

  // Simple Data Member for Testing
  //
  int data{};
};

}  // namespace mytest
