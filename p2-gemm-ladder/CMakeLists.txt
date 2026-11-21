if(NOT HAVE_CUDA)
  message(STATUS "p2-gemm-ladder: no CUDA compiler, skipping")
  return()
endif()

# GEMM Ladder: matmul kernels from naive to tensor cores, each explained with profiler evidence.
add_library(gemm src/gemm.cpp)
target_include_directories(gemm PUBLIC include)

add_executable(gemm_bench src/main.cpp)
target_link_libraries(gemm_bench PRIVATE gemm)

if(BUILD_TESTING)
  add_executable(gemm_tests tests/gemm_test.cpp)
  target_link_libraries(gemm_tests PRIVATE gemm GTest::gtest_main)
  gtest_discover_tests(gemm_tests)
endif()
