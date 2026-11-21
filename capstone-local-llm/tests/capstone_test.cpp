#include <gtest/gtest.h>

#include "graph/graph.h"
#include "serve/serve.h"

TEST(capstone, LinksEarlierProjects) {
    EXPECT_FALSE(graph::project_name().empty());
    EXPECT_FALSE(serve::project_name().empty());
}
