//
// Created by uyha on 6/19/2020.
//

#pragma once
#include "utils.hpp"

#include <utility>
namespace eop {
template <typename T>
concept equality_comparable = requires(T lhs, T rhs) {
  // clang-format off
  { lhs == rhs } -> boolean;
  { lhs != rhs } -> boolean;
  // clang-format on
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
  // clang-format off
  { lhs < rhs } -> boolean;
  { lhs > rhs } -> boolean;
  { lhs <= rhs } -> boolean;
  { lhs >= rhs } -> boolean;
  // clang-format on
};

template <typename T>
concept regular = equality_comparable<T> &&assignable<T> &&destructible<T>
    &&default_constructible<T> &&copy_constructible<T> &&total_ordered<T>;

template <typename Procedure, typename... Args>
concept regular_procedure = requires(Procedure procedure, Args &&... args) {
  // Since there's no way to determine if a procedure is regular or not, every procedure is
  {procedure(std::forward<Args>(args)...)};
};

template <typename Procedure, typename... Args>
concept functional_procedure = regular_procedure<Procedure, Args...> && (!pointer<Args> && ...);
} // namespace eop
