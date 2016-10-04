#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H


class BinaryTreeNode
{
    public:
        int nodeID;
        BinaryTreeNode(int nodeID);
        ~BinaryTreeNode();
    
        //member variables
        //pointers to child nodes
        BinaryTreeNode * leftChild;
        BinaryTreeNode * rightChild;

    private:

};

#endif // BINARYTREENODE_H
