#include <gtest/gtest.h>

#include "serve/serve.h"

TEST(serve, ProjectName) { EXPECT_EQ(serve::project_name(), "Mini vLLM"); }
