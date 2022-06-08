cmake_minimum_required(VERSION 3.22)
add_executable(surgery main.cpp ${INCLUDE_DIR}/operations.h ${INCLUDE_DIR}/point.h)
target_include_directories(surgery PUBLIC ${INCLUDE_DIR})