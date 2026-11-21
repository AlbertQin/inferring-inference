# Capstone: Local LLM Engine. Reuses P1 (graph runner) and P3 (KV cache, block manager).
add_executable(local_llm src/main.cpp)
target_link_libraries(local_llm PRIVATE graph serve)

if(BUILD_TESTING)
  add_executable(capstone_tests tests/capstone_test.cpp)
  target_link_libraries(capstone_tests PRIVATE graph serve GTest::gtest_main)
  gtest_discover_tests(capstone_tests)
endif()
