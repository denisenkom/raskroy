cmake_minimum_required (VERSION 2.6)

project (raskroy_test)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(raskroy_test Parser.cpp Perebor2d.cpp Perebor.cpp Raskroy.cpp Result.cpp types.cpp test.cpp)
target_link_libraries(raskroy_test ${GTEST_LIBRARIES} pthread)
