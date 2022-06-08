cmake_minimum_required(VERSION 3.22)

add_executable(task_2_pc_simulator main.cpp cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp ${INCLUDE_DIR}/cpu.h ${INCLUDE_DIR}/ram.h ${INCLUDE_DIR}/disk.h ${INCLUDE_DIR}/gpu.h ${INCLUDE_DIR}/kbd.h)

target_include_directories(task_2_pc_simulator PUBLIC ${INCLUDE_DIR})