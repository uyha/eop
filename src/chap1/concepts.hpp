//
// Created by uyha on 6/19/2020.
//

#pragma once
#include <concepts>
#include <type_traits>

namespace eop {
template <typename T>
concept boolean = std::is_convertible_v<std::remove_cvref_t<T>, bool>;

template <typename T>
concept equality_comparable = requires(T lhs, T rhs) {
  { lhs == rhs }
  ->boolean;
  { lhs != rhs }
  ->boolean;
};

template <typename T>
concept assignable = requires(T lhs, T rhs) {
  {lhs = rhs};
};

template <typename T>
concept destructible = requires(T self) {
  {self.~T()};
};

template <typename T>
concept default_constructible = requires {
  T{};
};

template <typename T>
concept copy_constructible = requires(T const &source) {
  T{source};
};

template <typename T>
concept total_ordered = equality_comparable<T> &&requires(T lhs, T rhs) {
  { lhs < rhs }
  ->boolean;
  { lhs > rhs }
  ->boolean;
  { lhs <= rhs }
  ->boolean;
  { lhs >= rhs }
  ->boolean;
};

template <typename T>
concept regular = equality_comparable<T> &&assignable<T> &&destructible<T>
    &&default_constructible<T> &&copy_constructible<T> &&total_ordered<T>;

template <typename Procedure>
concept regular_procedure = true;
} // namespace eop
