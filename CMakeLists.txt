cmake_minimum_required(VERSION 3.14)
project(dtw LANGUAGES C CXX)

set(CMAKE_BUILD_TYPE "Release")

if (NOT "${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    set(Prg-Intel "PrgEnv-intel")
    set(Prg-Clang "PrgEnv-cray")
    message(WARNING
            "Must use GNU Compiler for submission. Make sure you ran:\n"
            "module swap ${Prg-${CMAKE_C_COMPILER_ID}} PrgEnv-gnu")
endif ()

add_library(main OBJECT main.cpp)
target_compile_features(main PRIVATE cxx_std_11)

# SERIAL
add_executable(serial-dtw serial.cpp)
target_link_libraries(serial-dtw PRIVATE main)
target_compile_features(serial-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(serial-dtw PRIVATE -Wall -pedantic -march=native)
configure_file(serial-job.in serial-job)

# PARALLEL
add_executable(parallel-dtw parallel.cpp)
target_link_libraries(parallel-dtw PRIVATE main)
target_compile_features(parallel-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(parallel-dtw PRIVATE -Wall -pedantic -march=native)

# VARIABLE