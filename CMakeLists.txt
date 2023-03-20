cmake_minimum_required(VERSION 3.5)

project(libsktlrand
  VERSION 0.1
  DESCRIPTION "Samiur's Random library"
  LANGUAGES CXX)

add_library(libsktlrand STATIC src/mt.cc include/mt.h)
target_compile_features(libsktlrand PUBLIC cxx_std_11)

add_executable(mt_test src/mt_test.cc)
target_link_libraries(mt_test PUBLIC libsktlrand)
