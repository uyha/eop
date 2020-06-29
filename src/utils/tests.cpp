//
// Created by uyha on 6/28/2020.
//
#define CATCH_CONFIG_MAIN
#include "utils.hpp"

#include <catch/catch.hpp>

TEST_CASE("Pointer") {
  CHECK(eop::pointer<int *>);
  CHECK_FALSE(eop::pointer<int>);
}
