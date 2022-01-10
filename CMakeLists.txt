cmake_minimum_required(VERSION 3.10)

project(tracer)

file(GLOB SOURCES src/*.cpp)
add_library(tracer STATIC ${SOURCES})
target_include_directories(tracer PUBLIC inc)

file(GLOB SOURCES test/*.cpp)
add_executable(tracer_test ${SOURCES})
target_link_libraries(tracer_test tracer fmt-8)
