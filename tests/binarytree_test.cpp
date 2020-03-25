#include <gtest/gtest.h>
#include "../src/binarytree.h"

class BinaryTreeTest : public ::testing::Test
{
protected:
    BinaryTreeTest()
    : tree(1)
    {}
    virtual void SetUp(void)
    {
        /*
                   1 
             2           3
          4     5      6     7 
        8  9  
        */
       auto l2_1 = tree.setLeft(tree.root, 2);
       auto l2_2 = tree.setRight(tree.root, 3);

       auto l3_1_1 = tree.setLeft(l2_1, 4);
       auto l3_1_2 = tree.setRight(l2_1, 5);

       auto l3_2_1 = tree.setLeft(l2_2, 6);
       auto l3_2_2 = tree.setRight(l2_2, 7);

       auto l4_1_1 = tree.setLeft(l3_1_1, 8);
       auto l4_1_2 = tree.setRight(l3_1_1, 9);
    }

protected:
    BinaryTree<Node, int> tree;
};

TEST_F(BinaryTreeTest, preorder) {
    auto res = tree.preorder();
    int expectArr[9] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    for(int i=0; i<9; i++) {
        EXPECT_EQ(res->get(i), expectArr[i]);
    }
}

TEST_F(BinaryTreeTest, inorder) {
    auto res = tree.inorder();
    int expectArr[9] = {8, 4, 9, 2, 5, 1, 6, 3, 7};
    for(int i=0; i<9; i++) {
        EXPECT_EQ(res->get(i), expectArr[i]);
    }
}

TEST_F(BinaryTreeTest, postorder) {
    auto res = tree.postorder();
    int expectArr[9] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    for(int i=0; i<9; i++) {
        EXPECT_EQ(res->get(i), expectArr[i]);
    }
}
