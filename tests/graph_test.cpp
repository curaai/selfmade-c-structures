#include <gtest/gtest.h>
#include "../src/graph.h"

class GraphTest : public ::testing::Test
{
protected:
    Graph graph;
};

TEST_F(GraphTest, insert) {
    auto v1 = graph.insert(1, nullptr);
    auto v2 = graph.insert(2, nullptr);
    graph.addEdge(v2, v1);
    EXPECT_EQ(v2->isAdjacent(v1), true);
}