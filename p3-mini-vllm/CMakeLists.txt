# Mini vLLM: serving engine with KV cache, paged blocks and continuous batching.
add_library(serve src/serve.cpp)
target_include_directories(serve PUBLIC include)

add_executable(mini_vllm src/main.cpp)
target_link_libraries(mini_vllm PRIVATE serve)

if(BUILD_TESTING)
  add_executable(serve_tests tests/serve_test.cpp)
  target_link_libraries(serve_tests PRIVATE serve GTest::gtest_main)
  gtest_discover_tests(serve_tests)
endif()
