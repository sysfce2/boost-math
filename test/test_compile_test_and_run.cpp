//  Copyright John Maddock 2014.
//  Copyright Christopher Kormanyos 2024.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>
#include <boost/cstdfloat.hpp>

#include "compile_test/instantiate.hpp"

namespace local
{
  auto instantiate_runner() -> void
  {
    volatile bool result_instantiate_and_run_is_ok { false };
    #if defined(BOOST_FLOAT64_C)
    instantiate(BOOST_FLOAT64_C(1.23));
    result_instantiate_and_run_is_ok = true;
    #else
    result_instantiate_and_run_is_ok = true;
    #endif

    BOOST_TEST(result_instantiate_and_run_is_ok);
  }
}

auto main() -> int
{
  local::instantiate_runner();

  const auto result_is_ok = (boost::report_errors() == 0);

  return (result_is_ok ? 0 : -1);
}
