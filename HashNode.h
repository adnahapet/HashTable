//
//  HashNode.h
//  Assignment3
//
//  Created by Armen Nahapetian on 3/11/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <stdio.h>
#include <vector>


class HashNode {
public:
    
    HashNode(std::vector <int> triplet);
    
    ~HashNode();
    
    std::vector <int> data;
    
    HashNode * next;
    
};

#endif /* HashNode_h */
