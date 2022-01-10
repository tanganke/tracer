#include <catch2/catch.hpp>
#include <fmt/format.h>
#include <fmt/ranges.h>

#include "tracer/tracer.h"

TEST_CASE("tracer") {
  tracer<int> i;
  i = 1;
  i.mark();
  i = 2;
  i = 2 + i;
  i.mark();
  fmt::print("{}\n", i.history());
}

TEST_CASE("auto_tracer") {
  auto_tracer<int> i;
  i = 1;
  i = 2;
  i = 2 + i;
  fmt::print("{}\n", i.history());
}
