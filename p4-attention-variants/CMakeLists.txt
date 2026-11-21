# Attention Variant Study: MHA, MQA, GQA, sliding window and MoE plugged into the P3 engine.
add_library(variants src/variants.cpp)
target_include_directories(variants PUBLIC include)
target_link_libraries(variants PUBLIC serve)

add_executable(variant_study src/main.cpp)
target_link_libraries(variant_study PRIVATE variants)

if(BUILD_TESTING)
  add_executable(variants_tests tests/variants_test.cpp)
  target_link_libraries(variants_tests PRIVATE variants GTest::gtest_main)
  gtest_discover_tests(variants_tests)
endif()
