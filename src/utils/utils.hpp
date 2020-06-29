//
// Created by uyha on 6/28/2020.
//

#pragma once
#include <type_traits>

namespace eop {
struct false_type {
  static constexpr bool value = false;
};
struct true_type {
  static constexpr bool value = true;
};

template <typename T>
struct is_pointer : false_type {};

template <typename T>
struct is_pointer<T *> : true_type {};

template <typename T>
concept pointer = is_pointer<T>::value;

template <typename T>
concept boolean = requires(T value) {
  {bool(value)};
};
} // namespace eop
