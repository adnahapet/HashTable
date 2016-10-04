//
//  LinkedList.cpp
//  calculator
//
//  Created by Armen Nahapetian on 2/17/16.
//  Copyright © 2016 Armen Nahapetian. All rights reserved.
//

#include "LinkedList.h"

//void constructor initializes pointers to nullptr and size to 0
LinkedList::LinkedList():
    head(nullptr),
    tail(nullptr),
    size(0)
{
    
    
}


//destructor calls removeathead repeatedly until it returns to the tail
LinkedList::~LinkedList(){
    if(head != nullptr) {
        while(head->next !=nullptr){
        removeAtHead();
        }
        delete tail;
    }
}


//Inserts paramter node into list as new head
//Checks for condition that list is empty first
//If empty makes first node both head and tail
void LinkedList::Insert(HashNode * node){
    if(tail==nullptr){
        node->next = nullptr;
        tail = node;
        head = node;
    }
    else{
        node->next = head;
        head = node;
    }
    size++;
}


//removes head from list and iterates backwards to the previous node in the list
//makes previous node new head
HashNode *  LinkedList::removeAtHead(){
   
    HashNode * oldHead = head;
    head = head->next;
    delete oldHead;
    
    --size;
    
    return head;

}