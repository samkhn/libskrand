cmake_minimum_required(VERSION 3.5)

project(xrand
  VERSION 0.1
  DESCRIPTION "Experiments in randomness"
  LANGUAGES CXX)

add_library(libskrand STATIC mt.cc mt.h)
target_compile_features(libskrand PUBLIC cxx_std_11)

add_executable(mt_test mt_test.cc)
target_link_libraries(mt_test PUBLIC libskrand)
