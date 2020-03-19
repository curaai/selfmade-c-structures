#include "linkedlist.h"

#define BUCKET_SIZE 1039


struct TableItem
{
    int key;
    int value;
};

struct Bucket
{
    LinkedList<TableItem>* chain;
    int idx;
};

class ChainHashTable
{
public:
    ChainHashTable(){};
    ~ChainHashTable(){};

    int get(int k);
    void insert(int k, int value);
    void remove(int k);
    Bucket find(int k);
    static int hash(int k);

public:
    const int n {BUCKET_SIZE};
    LinkedList<TableItem> buckets[BUCKET_SIZE];
};