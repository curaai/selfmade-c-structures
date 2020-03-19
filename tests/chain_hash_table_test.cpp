#include <gtest/gtest.h>
#include "../src/chain_hash_table.h"

class ChainHashTableTest : public ::testing::Test
{
protected:
    ChainHashTable table;
};

TEST_F(ChainHashTableTest, hash) {
    int res = table.hash(1);
    EXPECT_EQ(res, (1 * 79 + 931) % BUCKET_SIZE);
}

TEST_F(ChainHashTableTest, insert) {
    table.insert(4, 100);
    int v = table.get(4);
    EXPECT_EQ(v, 100);

    EXPECT_THROW(table.get(-1), std::invalid_argument);
}

TEST_F(ChainHashTableTest, find) {
    table.insert(1, 100);
    Bucket isFind = table.find(1);
    EXPECT_NE(isFind.idx, -1);
}

TEST_F(ChainHashTableTest, remove) {
    table.insert(1, 100);
    Bucket isFind = table.find(1);
    EXPECT_NE(isFind.idx, -1);
    table.remove(1);
    Bucket isFind2 = table.find(1);
    EXPECT_EQ(isFind2.idx, -1);
}
