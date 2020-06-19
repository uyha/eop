//
// Created by uyha on 6/19/2020.
//

#define CATCH_CONFIG_MAIN
#include "concepts.hpp"

#include <catch/catch.hpp>

using namespace eop;

TEMPLATE_TEST_CASE("Concepts for built-in types",
                   "[concepts][built-in]",
                   bool,
                   char,
                   signed char,
                   unsigned short int,
                   unsigned int,
                   unsigned long,
                   signed short int,
                   signed int,
                   signed long) {
  CHECK(equality_comparable<TestType>);
  CHECK(assignable<TestType>);
  CHECK(destructible<TestType>);
  CHECK(default_constructible<TestType>);
  CHECK(copy_constructible<TestType>);
  CHECK(total_ordered<TestType>);
  CHECK(regular<TestType>);
}
