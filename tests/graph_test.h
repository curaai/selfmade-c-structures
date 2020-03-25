#include <gtest/gtest.h>
#include "../src/graph.h"

class GraphTest : public ::testing::Test
{
protected:
    Graph graph;
};

TEST_F(GraphTest, insert) {
    auto v1 = graph.insert(1, nullptr);
    LinkedList<Vertex*> v2Edge;
    v2Edge.add(v1);
    auto v2 = graph.insert(2, v2Edge);
    EXPECT_EQ(v2->isAdjacent(v1), true);
}