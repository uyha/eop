//
// Created by uyha on 6/19/2020.
//

#define CATCH_CONFIG_MAIN
#include "concepts.hpp"

#include <catch/h.hpp>
#include <river/type_list.hpp>

using namespace eop;

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
  CHECK(equality_comparable<TestType>);
  CHECK(assignable<TestType>);
  CHECK(destructible<TestType>);
  CHECK(default_constructible<TestType>);
  CHECK(copy_constructible<TestType>);
  CHECK(total_ordered<TestType>);
  CHECK(regular<TestType>);
}
