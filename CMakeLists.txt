cmake_minimum_required(VERSION 3.5)

project(libsktlrand
  VERSION 0.1
  DESCRIPTION "Samiur's Random library"
  LANGUAGES CXX)

add_library(sktlrand INTERFACE)
target_include_directories(sktlrand INTERFACE include/)
target_compile_features(sktlrand INTERFACE cxx_std_11)

add_executable(mt_test src/mt_test.cc)
target_link_libraries(mt_test PUBLIC sktlrand)

add_executable(lcg_test src/lcg_test.cc)
target_link_libraries(lcg_test PUBLIC sktlrand)
