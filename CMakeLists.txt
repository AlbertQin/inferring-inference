cmake_minimum_required(VERSION 3.25)
project(inferring_inference LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# CUDA is optional: on the Mac it's absent and CUDA-only parts are skipped.
include(CheckLanguage)
check_language(CUDA)
if(CMAKE_CUDA_COMPILER)
  enable_language(CUDA)
  set(HAVE_CUDA ON)
endif()

# Tests: GoogleTest, downloaded at configure time. Run with `ctest --test-dir build`.
include(CTest)
if(BUILD_TESTING)
  include(FetchContent)
  FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
    SYSTEM)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # Windows: match our C runtime
  FetchContent_MakeAvailable(googletest)
  target_compile_options(gtest PRIVATE -w)  # third-party code: no warnings
  include(GoogleTest)
endif()

# Warnings for our code only (added after GoogleTest so it isn't affected).
if(MSVC)
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:/W4>)
else()
  add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Wall$<SEMICOLON>-Wextra$<SEMICOLON>-Wpedantic>)
endif()

add_subdirectory(p1-graph-runner)        # Ch 1: CPU
add_subdirectory(p2-gemm-ladder)         # Ch 2: CUDA only
add_subdirectory(p3-mini-vllm)           # Ch 3: CPU core, CUDA kernels later
add_subdirectory(p4-attention-variants)  # Ch 4: builds on P3
add_subdirectory(capstone-local-llm)     # Ch 6: reuses P1 and P3, Metal later
# P5 (NPU simulator) is Python, not part of the CMake build.
