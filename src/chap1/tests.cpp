//
// Created by uyha on 6/19/2020.
//

#define CATCH_CONFIG_MAIN
#include "concepts.hpp"
#include "types.hpp"

#include <catch/catch.hpp>
#include <concepts>
#include <river/type_list.hpp>

using built_in_types = river::type_list<bool,
                                        char,
                                        unsigned char,
                                        unsigned short,
                                        unsigned int,
                                        unsigned long,
                                        unsigned long long,
                                        signed char,
                                        signed short,
                                        signed int,
                                        signed long,
                                        signed long long,
                                        float,
                                        double>;

TEMPLATE_LIST_TEST_CASE("Concepts for built-in types", "[concepts][built-in]", built_in_types) {
  CHECK(eop::regular<TestType>);
  CHECK(eop::regular<TestType *>);
  CHECK_FALSE(eop::regular<TestType &>);
}

TEST_CASE("Concepts for user defined type", "[concepts][user-defined]") {
  CHECK(eop::regular<eop::Regular>);
  CHECK(eop::regular<eop::Regular *>);
  CHECK_FALSE(eop::regular<eop::Regular &>);
}

TEST_CASE("Regular procedure") {
  CHECK(eop::regular_procedure<void (*)()>);
  CHECK(eop::regular_procedure<void (*)(int, int), int, int>);

  CHECK(eop::regular_procedure<void (*)(eop::Regular), eop::Regular>);
  CHECK(eop::regular_procedure<void (*)(eop::Regular), eop::Regular &>);
  CHECK(eop::regular_procedure<void (*)(eop::Regular), eop::Regular &&>);

  CHECK(eop::regular_procedure<void (*)(eop::Regular &), eop::Regular &>);

  CHECK(eop::regular_procedure<void (*)(eop::Regular &&), eop::Regular>);
  CHECK(eop::regular_procedure<void (*)(eop::Regular &&), eop::Regular &&>);

  CHECK(eop::regular_procedure<void (*)(int *, int *, int *), int *, int *, int *>);

  CHECK_FALSE(eop::regular_procedure<void>);
}

TEST_CASE("Functional procedure") {
  CHECK(eop::functional_procedure<int (*)(int), int>);
  CHECK_FALSE(eop::functional_procedure<void (*)(int *, int *), int *, int *>);
}
