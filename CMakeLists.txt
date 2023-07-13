cmake_minimum_required(VERSION 3.22)
project(Test CXX)

set(CMAKE_CXX_STANDARD 17)

set(GTEST_HAS_ABSL TRUE)
set(INSTALL_GTEST FALSE)

add_subdirectory(externals/re2 EXCLUDE_FROM_ALL SYSTEM)
add_subdirectory(externals/abseil EXCLUDE_FROM_ALL SYSTEM)
add_subdirectory(externals/gtest EXCLUDE_FROM_ALL SYSTEM)


add_executable(my-test test.cpp)
target_link_libraries(my-test PRIVATE GTest::gtest_main)
