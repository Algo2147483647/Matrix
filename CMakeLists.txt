# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project (Matrix)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable (Graphics "test/main.cpp" "include/LinearAlgebra.h" "test/EigTest.cpp" "test/Test.h" "test/BasicAlgebraTest.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Graphics PROPERTY CXX_STANDARD 20)
endif()