cmake_minimum_required(VERSION 3.22)
add_executable(surgery main.cpp)
target_include_directories(surgery PUBLIC ${INCLUDE_DIR})