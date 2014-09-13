cmake_minimum_required(VERSION 3.0)
project(promise)

set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/out)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

include_directories(
  ${CMAKE_SOURCE_DIR}
)

add_executable(
  promise-test
  test.c
  promise.c
  promise.h
)

add_library(
  promise
  promise.c
  promise.h
)



target_link_libraries (promise)

