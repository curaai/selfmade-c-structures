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
            22      
          15  50 
            43  75
        */
        int testData[4] = {22, 15, 43, 75};
        for(auto x : testData)
            tree.insert(x);
    }

protected:
    BinarySearchTree<int> tree;
};

TEST_F(BinarySearchTreeTest, simple_insert) {
        /*
             22      
          15     50 
        02     43  75
        */
    tree.insert(2);
    EXPECT_EQ(tree.root->left->left->item, 2);
}

TEST_F(BinarySearchTreeTest, RRrotation) {
    /*
          22   
      15      50 
            43  75
                   80
          |
          ▼
           50 
        22     75
      15  43     80
    */
    tree.insert(80);
    EXPECT_EQ(tree.root->item, 50);
    EXPECT_EQ(tree.root->left->item, 22);
    EXPECT_EQ(tree.root->left->left->item, 15);
    EXPECT_EQ(tree.root->left->right->item, 43);
    EXPECT_EQ(tree.root->right->item, 75);
    EXPECT_EQ(tree.root->right->right->item, 80);
}

TEST_F(BinarySearchTreeTest, LLrotation) {
    /*
          22   
      15      50 
    14      43  75
  13
          |
          ▼
          22   
      14      50 
    13  15  43  75
    */
    tree.insert(14);
    tree.insert(13);
    EXPECT_EQ(tree.root->left->item, 14);
    EXPECT_EQ(tree.root->left->left->item, 13);
    EXPECT_EQ(tree.root->left->right->item, 15);
}

TEST_F(BinarySearchTreeTest, allinone) {
    /*
      27
         45
       35
      |  perfom RL rotation
      ▼
      35    
    27  45
    */
    BinarySearchTree<int> t {27};
    t.insert(45);
    t.insert(34);
    EXPECT_EQ(t.root->item, 34);
    EXPECT_EQ(t.root->left->item, 27);
    EXPECT_EQ(t.root->right->item, 45);

    /*
          34    
        27  45
      20
    11
          |  perfom LL rotation
          ▼
            34    
        20     45
      11  27
    */
    t.insert(20);
    t.insert(11);
    EXPECT_EQ(t.root->left->item, 20);
    EXPECT_EQ(t.root->left->left->item, 11);
    EXPECT_EQ(t.root->left->right->item, 27);

    /*
               34    
         20         45
      11   27         59  
    10   25  29
               30
               |  perfom LR rotation
               ▼
              27    
         20         34
      11   25    29   45  
    10             30   59
    */
    t.insert(59);
    t.insert(10);
    t.insert(25);
    t.insert(29);
    t.insert(30);
    EXPECT_EQ(t.root->item, 27);
    EXPECT_EQ(t.root->left->item, 20);
    EXPECT_EQ(t.root->left->left->item, 11);
    EXPECT_EQ(t.root->left->right->item, 25);
    EXPECT_EQ(t.root->left->left->left->item, 10);
    EXPECT_EQ(t.root->right->item, 34);
    EXPECT_EQ(t.root->right->left->item, 29);
    EXPECT_EQ(t.root->right->right->item, 45);
    EXPECT_EQ(t.root->right->right->right->item, 59);
    EXPECT_EQ(t.root->right->left->right->item, 30);
}