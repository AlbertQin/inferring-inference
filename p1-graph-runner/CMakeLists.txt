# Graph Runner: loads an .onnx file and runs inference without PyTorch.
add_library(graph src/graph.cpp)
target_include_directories(graph PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE graph)

if(BUILD_TESTING)
  add_executable(graph_tests tests/graph_test.cpp)
  target_link_libraries(graph_tests PRIVATE graph GTest::gtest_main)
  gtest_discover_tests(graph_tests)
endif()
