cmake_minimum_required(VERSION 3.14)  # Minimum for FetchContent
project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
file(GLOB SRCS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Main executable
add_executable(OrderBook main.cpp ${SRCS})

# ---------------- GoogleTest Setup ----------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Test sources
file(GLOB TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/test/*.cpp)

# Test executable
add_executable(TestOrderBook ${TEST_SOURCES} ${SRCS})  # Include SRCS so test can link to Order.cpp
target_link_libraries(TestOrderBook GTest::gtest_main)

# Auto discover tests
include(GoogleTest)
gtest_discover_tests(TestOrderBook)
