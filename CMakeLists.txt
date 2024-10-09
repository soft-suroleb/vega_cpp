cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

project(vega_cpp)

include_directories(include)

add_executable(main main.cpp src/addition.cpp)

include(FetchContent)
set(BENCHMARK_ENABLE_TESTING off)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.9.0
)
FetchContent_MakeAvailable(googletest googlebenchmark)

enable_testing()
add_executable(tests tests/test_add.cpp src/addition.cpp)
target_link_libraries(tests gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)

add_executable(bm benchmark/main.cpp src/addition.cpp)
target_link_libraries(bm benchmark::benchmark)

# find_package(Doxygen)
# if(DOXYGEN_FOUND)

#     set(DOXYGEN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/docs)
#     set(DOXYGEN_INPUT ${DOXYGEN_DIR}/Doxyfile.in)
#     set(DOXYGEN_OUTPUT ${DOXYGEN_DIR}/Doxyfile)

#     configure_file(${DOXYGEN_INPUT} ${DOXYGEN_OUTPUT} @ONLY)
#     add_custom_target(
#         docs
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUTPUT}
#         WORKING_DIRECTORY ${DOXYGEN_DIR}
#         VERBATIM
#     )

# else(DOXYGEN_FOUND)
#     message(STATUS "WARNING: Doxygen not found - Reference manual will not be created")
# endif(DOXYGEN_FOUND)
