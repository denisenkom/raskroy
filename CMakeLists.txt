cmake_minimum_required (VERSION 2.6)

if(CMAKE_COMPILER_IS_GNUCXX)
    list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")
endif()

project (guillotine_test)

add_library(guillotine_interop MODULE guillotine_interop.cpp layout1d.cpp layout2d.cpp result.cpp results_generator.cpp types.cpp)
