add_library(BigInteger)

target_sources(BigInteger PRIVATE BigInteger.cpp PUBLIC BigInteger.h )
target_include_directories(BigInteger PUBLIC ${CMAKE_CURRENT_LIST_DIR})
