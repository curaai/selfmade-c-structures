#include <gtest/gtest.h>
#include "../src/linkedlist.h"

class LinkedListTest : public ::testing::Test
{
protected:
    LinkedListTest() {};
    virtual void SetUp(void)
    {
        for(auto x : items)
            list.add(x);
    }

protected:
    int items[6] = {1, 2, 3, 4, 5, 6};
    LinkedList<int> list;
};


TEST_F(LinkedListTest, CheckElements) {
    const int cnt=6;
    for(int i=0; i<cnt; i++) {
        EXPECT_EQ(list.get(i), items[i]);
    }
}

TEST_F(LinkedListTest, RemoveElement) {
    EXPECT_EQ(list.get(2), 3);
    list.remove(2);
    EXPECT_EQ(list.get(2), 4);
}
