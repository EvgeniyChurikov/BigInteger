include(FetchContent)
FetchContent_Declare(gtest
  QUIET
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
)
FetchContent_MakeAvailable(gtest)

add_executable(unit_tests
        CopyTests.cpp
        AssignmentTests.cpp
        EqualTests.cpp
        OutputTests.cpp
        AddTests.cpp
        SubTests.cpp
        MulTests.cpp
        DivTests.cpp)
target_link_libraries(unit_tests PRIVATE BigInteger gtest_main)
