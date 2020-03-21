#include <gtest/gtest.h>
#include "../src/set.h"

class SetTest : public ::testing::Test
{
protected:
    SetTest(){}
    ~SetTest(){}
protected:
    Set a{{1, 3, 5}}; 
    Set b{{2, 4, 6}}; 
    Set c{{1, 2, 3}};
};


TEST_F(SetTest, union) {
    auto unionSet = a | b;
    auto testData = Set({1, 2, 3, 4, 5, 6});
    auto res = unionSet ==  testData;
    EXPECT_EQ(res, true);
}

TEST_F(SetTest, intersection) {
    auto testData = (a & c);
    bool res = Set({1, 3}) == testData;
    EXPECT_EQ(res, true);
}

TEST_F(SetTest, difference) {
    Set diff ({5});
    auto testData = (a - c);
    EXPECT_EQ(diff == testData, true);
}

TEST_F(SetTest, subset) {
    Set sub ({1, 3});
    EXPECT_EQ(sub < a, true);
    EXPECT_EQ(c < a, false);
}

