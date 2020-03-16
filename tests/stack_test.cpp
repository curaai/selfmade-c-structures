#include <gtest/gtest.h>
#include "../src/stack.h"

class StackTest : public ::testing::Test
{
protected:
    StackTest() {};

protected:
    Stack stack; 
};


TEST_F(StackTest, Push) {
    for(int i=0; i<3; i++)
        stack.push(i);
    EXPECT_EQ(stack.getSize(), 3);
}

TEST_F(StackTest, Pop) {
    for(int i=0; i<3; i++)
        stack.push(i);
    for(int i=2; i>=0; i--)
        EXPECT_EQ(stack.pop(), i);
}

TEST_F(StackTest, PopOnEmptyStack) {
    EXPECT_THROW(stack.pop(), std::length_error);
}

TEST_F(StackTest, RepeatPushPop) {
    // 2 > 3 > 1
    stack.push(2);
    stack.push(3);
    stack.push(1);
    // 2 > 3 
    EXPECT_EQ(stack.pop(), 1);
    // 2 > 3 > 4 
    stack.push(4);

    for(int i=4; i>=2; i--)
        EXPECT_EQ(stack.pop(), i);
}