#include <gtest/gtest.h>
#include "../src/queue.h"

class QueueTest : public ::testing::Test
{
protected:
    QueueTest() {};

protected:
    Queue queue; 
};


TEST_F(QueueTest, Push) {
    for(int i=0; i<3; i++)
        queue.push(i);
    EXPECT_EQ(queue.getSize(), 3);
}

TEST_F(QueueTest, Pop) {
    for(int i=0; i<3; i++)
        queue.push(i);
    for(int i=0; i<3; i++)
        EXPECT_EQ(queue.pop(), i);
}

TEST_F(QueueTest, PopOnEmptyStack) {
    EXPECT_THROW(queue.pop(), std::length_error);
}

TEST_F(QueueTest, RepeatPushPop) {
    // 2 > 3 > 1
    queue.push(2);
    queue.push(3);
    queue.push(1);
    // 3 > 1
    EXPECT_EQ(queue.pop(), 2);
    // 3 > 1 > 4 
    queue.push(4);

    EXPECT_EQ(queue.pop(), 3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 4);

    EXPECT_EQ(queue.getSize(), 0);
}