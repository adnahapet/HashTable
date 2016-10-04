//
//  HashNode.cpp
//  Assignment3
//
//  Created by Armen Nahapetian on 3/11/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "HashNode.h"

//a simple node for a linked list that contains a data element of type vector and a pointer to the next node in the list
HashNode::HashNode(std::vector <int> triplet):
    data(triplet),
    next(nullptr)
{

}

HashNode::~HashNode(){
    
    //delete  next;
    
}