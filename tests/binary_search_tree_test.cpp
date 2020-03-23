#include <gtest/gtest.h>
#include "../src/binary_search_tree.h"

class BinarySearchTreeTest : public ::testing::Test
{
protected:
    BinarySearchTreeTest()
    : tree(50)
    {}
    virtual void SetUp(void)
    {
        /*
              50
          22      75
        15  43 
        */
        int testData[4] = {22, 15, 43, 75};
        for(auto x : testData)
            tree.insert(x);
    }

protected:
    BinarySearchTree<int> tree;
};

TEST_F(BinarySearchTreeTest, simple_insert) {
    tree.insert(2);
}