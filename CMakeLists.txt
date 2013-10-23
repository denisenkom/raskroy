cmake_minimum_required (VERSION 2.6)

if(CMAKE_COMPILER_IS_GNUCXX)
    list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif()

project (raskroy_test)

# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(raskroy_test Parser.cpp layout2d.cpp layout1d.cpp Raskroy.cpp Result.cpp types.cpp test.cpp)
#target_link_libraries(raskroy_test ${GTEST_LIBRARIES} pthread)

add_library(guillotine_interop MODULE guillotine_interop.cpp layout1d.cpp layout2d.cpp result.cpp raskroy.cpp types.cpp)
