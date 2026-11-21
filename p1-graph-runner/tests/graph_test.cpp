#include <gtest/gtest.h>

#include "graph/graph.h"

TEST(graph, ProjectName) { EXPECT_EQ(graph::project_name(), "Graph Runner"); }
