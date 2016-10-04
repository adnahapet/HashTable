#ifndef HASH_H
#define HASH_H
#include <vector>

#include "LinkedList.h"

class Hash
{
    public:
    
        Hash(int hashSize);
        ~Hash();
        int hashFunc(std::vector<int> triplet);
        void insert(std::vector<int> triplet);
        std::vector<int> search(int key);

    private:
        int hashSize;
        std::vector<LinkedList> hashTable;
};

#endif // HASH_H
