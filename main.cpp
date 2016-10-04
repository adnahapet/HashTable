//
//  main.cpp
//  Assignment3
//
//  Created by Armen Nahapetian on 3/10/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//


//inludes necessary standard library
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


//includes new classes hash and binary tree
//binary tree will parse hash table for implementation
#include "hash.h"
#include "binarytree.h"


int main(int argc, const char * argv[]) {
 
    
    std::vector <std::vector <int>> triplets;
    std::string data;
    std::string token;
    std::ifstream infile;
    std::string inputFile;
    
    int numberofNodes;
    int hashSize;

    
    inputFile = argv[1];
    infile.open(inputFile);
    
    
    //loops through taking every line from text file
    // tokenizes the text and inputs each integer into a vector
    while(infile.good())
    {
        getline(infile,data);
        std::istringstream ss(data);
        std::vector <int> temp;
        for(int i =0; i < 3; i++){
            getline(ss,token,' ');
            if (token!= ""){
                temp.push_back(std::stoi(token));
            }
        }
        triplets.push_back(temp);
        temp.clear();
    }
    
    //parses the data from the first line of the text file for variables
    //assuming first line is always not a valid triplet but definition information
    numberofNodes = triplets[0][0];
    hashSize = triplets[0][1];
    
    
    //initiates new hash table of size indicated by text file
    Hash * hash = new Hash(hashSize);
    
    //loops through inserting a vector of triplets into hash table as a node in a linked list
    //insert method calls hashFunc and LinkedList::Insert remotely
    for(int i = 1; i < numberofNodes+1;i++){
        hash->insert(triplets[i]);
    }
    
    // creates new binary tree
    BinaryTree tree = *new BinaryTree();
    
    
    //finds rootID by finding the only parentID in data set that isn't present in other vectors as a child nodeID
    int rootID = tree.findRoot(triplets, numberofNodes);
    
    
    //recursive construction call that uses hash table as data set and rootID as a starting point
    tree.construct(hash, rootID);
    
    
    //recursive traversal call that uses root pointer member of BinaryTree as a starting point
    tree.postOrder(tree.root);
    
    
    return 0;
}
