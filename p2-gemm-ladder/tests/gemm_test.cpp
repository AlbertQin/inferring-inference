#include <gtest/gtest.h>

#include "gemm/gemm.h"

TEST(gemm, ProjectName) { EXPECT_EQ(gemm::project_name(), "GEMM Ladder"); }
