cmake_minimum_required(VERSION 3.31.6)
project(OrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(OrderBook main.cpp)