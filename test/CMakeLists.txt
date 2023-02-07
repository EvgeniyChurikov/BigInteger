include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests BigIntegerTests.cpp)
target_link_libraries(unit_tests PRIVATE BigInteger gtest_main)
