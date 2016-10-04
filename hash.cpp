#include "hash.h"


//takes in the hashSize value from the text file and creates a vector of that size
//fills with linked lists
Hash::Hash(int hashSize):
    hashSize(hashSize)
{
    for(int i = 0; i <hashSize;i++){
        hashTable.push_back( *new LinkedList);
    }
}

Hash::~Hash(){

}

//returns the remainder of the parentID in a triplet / the size of the hash table
int Hash::hashFunc(std::vector<int> triplet){
    int index = triplet[0] % hashSize;
    return index;
}


//inserts a new node into a linked list
// calls the hashFunc to determine which index(linked list) to insert into
// then calls Linked List class native Insert (notice caps) method
void Hash::insert(std::vector<int> triplet){
    
    HashNode * newNode = new HashNode(triplet);
    int target = hashFunc(triplet);
    
    hashTable[target].Insert(newNode);

}


//determines the correct linked list to parse by performing same operation as hashFunc
//starts at Head of Linked List in appropriate vector and then traverses list
//looks for triple containing key in parentID position and returns vector
std::vector <int> Hash::search(int key){
    
    size_t searchIndex = key % hashSize;
    
    HashNode search = *hashTable[searchIndex].head;
    
    while(key != search.data[0]){
        if(search.next != nullptr)
            search = *search.next;
    }
    
    
    return search.data;
    
}
