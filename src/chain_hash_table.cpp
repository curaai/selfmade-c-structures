#include "chain_hash_table.h"

int ChainHashTable::get(int k)
{
    auto bucket = find(k);
    if(bucket.idx == -1)
        throw std::invalid_argument("Can't find key");
    
    return bucket.chain->get(bucket.idx)->item.value;
}

void ChainHashTable::insert(int k, int v)
{
    int code = hash(k);
    auto chain = &buckets[code];
    chain->add(TableItem{k, v});
}

void ChainHashTable::remove(int k)
{
    auto bucket = find(k);
    if(bucket.idx == -1)
        throw std::invalid_argument("Can't find key");
    
    bucket.chain->remove(bucket.idx);
}


Bucket ChainHashTable::find(int k)
{
    int code = hash(k);
    auto chain = &buckets[code];
    for(int i=0; i<chain->length; i++) {
        TableItem item = chain->get(i)->item; 
        if(k == item.key)
            return Bucket{chain, i};
    }
    return Bucket{chain, -1};
}

int ChainHashTable::hash(int k)
{
    return (k * 79 + 931) % BUCKET_SIZE;
}