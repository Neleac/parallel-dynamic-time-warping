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

# ROW (serial)
add_executable(row-dtw row.cpp)
target_link_libraries(row-dtw PRIVATE main)
target_compile_features(row-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(row-dtw PRIVATE -Wall -pedantic -march=native)
set(TRAVERSAL "row")
configure_file(serial-job.in ${TRAVERSAL}-job)

# DIAGONAL (serial)
add_executable(diagonal-dtw diagonal.cpp)
target_link_libraries(diagonal-dtw PRIVATE main)
target_compile_features(diagonal-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(diagonal-dtw PRIVATE -Wall -pedantic -march=native)
set(TRAVERSAL "diagonal")
configure_file(serial-job.in ${TRAVERSAL}-job)

# PARALLEL
add_executable(parallel-dtw parallel.cpp)
target_link_libraries(parallel-dtw PRIVATE main)
target_link_options(parallel-dtw PRIVATE -fopenmp)
target_compile_features(parallel-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(parallel-dtw PRIVATE -fopenmp -Wall -pedantic -march=native)
configure_file(parallel-job.in parallel-job)

# VARIABLE
add_executable(variable-dtw variable.cpp)
target_link_libraries(variable-dtw PRIVATE main)
target_link_options(variable-dtw PRIVATE -fopenmp)
target_compile_features(variable-dtw PRIVATE c_std_11 c_restrict)
target_compile_options(variable-dtw PRIVATE -fopenmp -Wall -pedantic -march=native)
set(TRAVERSAL "variable")
configure_file(serial-job.in ${TRAVERSAL}-job)