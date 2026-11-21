#include <gtest/gtest.h>

#include "variants/variants.h"

TEST(variants, ProjectName) { EXPECT_EQ(variants::project_name(), "Attention Variant Study"); }
