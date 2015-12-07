//
//  Node.cpp
//  220-19-Nodes
//
//  Created by Toby Dragon on 10/8/15.
//  Copyright (c) 2015 Toby Dragon. All rights reserved.
//

#include "Node.h"
#include <iostream>

Node::Node(std::string nameIn, int idNumberIn){
    name = nameIn;
    idNumber = idNumberIn;
    next = nullptr;
}

std::string Node::getName(){
    return name;
}

int Node::getIdNumber(){
    return idNumber;
}

Node* Node::getNext(){
    return next;
}
void Node::setNext(Node* nextIn){
    next = nextIn;
}