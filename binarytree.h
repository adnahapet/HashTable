#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

#include "hash.h"
#include "binarytreenode.h"

class BinaryTree
{
    public:
    
        //default constructor
        BinaryTree();
    
        // destructor that works recursively
        ~BinaryTree();
    
        //finds root by parsing whole set of triplets
        int findRoot(std::vector<std::vector<int>> tripletList, int nTriplets);
    
        //recursive function to construct table
        BinaryTreeNode * construct(Hash * hash, int rootID);
    
        //recursive function to print nodeIDs, should take in root as initial parameter
        void postOrder(BinaryTreeNode * node);
    
        //recursive function for destructor call
       void removeNode(BinaryTreeNode * node);
    
        //pointer to root node, set by construct function
        BinaryTreeNode * root;
    

    
    
};




#endif // BINARYTREE_H
