cmake_minimum_required (VERSION 3.8)
project (Matrix)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(googletest)

file(GLOB PROJECT_SOURCES
     "${PROJECT_SOURCE_DIR}/test/*.cpp"
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include/
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} gtest gtest_main)