#include "binarytree.h"


//basic void constructor that sets the root pointer to nullptr
//the rest of Binary Tree methods are called from Main()
BinaryTree::BinaryTree():
    root(nullptr)
{

}

//default destructor uses recursive call to removeNode with root pointer as initial parameter 
BinaryTree::~BinaryTree()
{
    removeNode(root);
}


//the provided files have roots as the second line of the text
//this method assumes the root could be on any line
int BinaryTree::findRoot(std::vector<std::vector<int>> Triplets,int nTriplets){

    //the method sets the initial possible root id as the first digit in the first 3 digit vector
    //it then iterates through the entire data set multiple times if necessary comparing each possible rootID
    //to the children on each line until it finds the parentID that isn't a child of any others
    int rootID = Triplets[1][0];
    int z = 0;
    while( z < nTriplets+1){
        
        for(int i=1;i < nTriplets+1;i++){
            if(rootID == Triplets[i][1] || rootID == Triplets [i][2])
                rootID = Triplets [i][0];
        }
    
        z++;
    
    }
    return rootID;
}


//a recursive method to construct a tree
BinaryTreeNode * BinaryTree::construct(Hash * hash, int rootID){
    
    //the base case for when a leaf node with no children is encountered
    if(rootID == -1)
        return nullptr;
    
    // the hash table is searched for the Root on the intial call while subsequent methods will take in child IDs
    // as the new parent ID
    // a chain of -> right child constructs is called until a nullptr is encountered
    // the method will return to the previous call and create a left child
    // and then alternate back to right child construction calls until a nullptr is encountered again
    else{
        std:: vector <int> temp = hash->search(rootID);
        BinaryTreeNode * newNode = new BinaryTreeNode(rootID);
        
        if(root ==nullptr){
            root = newNode;
        }
        newNode->rightChild = construct(hash,temp[2]);
        newNode->leftChild = construct(hash,temp[1]);
        return newNode;
    }
}

// uses same post order traversal to delete child nodes working way back up to root
// sets left and right child to nullptr and then deletes node
void BinaryTree::removeNode(BinaryTreeNode * node){
    
    if(node != nullptr){
        removeNode(node->leftChild);
        removeNode(node->rightChild);
        node->leftChild = nullptr;
        node->rightChild = nullptr;
        delete node;
    }
    
}

//uses more or less the same logic as construction, traverses list using nullptr as a bound and then pops off
// traverses child nodes before returning to parent
void BinaryTree::postOrder(BinaryTreeNode * node){
    if(node != nullptr){
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        std::cout<<node->nodeID<<std::endl;
    }
}
