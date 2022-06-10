cmake_minimum_required(VERSION 3.22)

add_executable(task_2_pc_simulator main.cpp cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp)

target_include_directories(task_2_pc_simulator PUBLIC ${INCLUDE_DIR})