//
//  QueueADT.h
//  220-19-Nodes
//
//  Created by Toby Dragon on 10/19/15.
//  Copyright (c) 2015 Toby Dragon. All rights reserved.
//

#ifndef _20_19_Nodes_QueueADT_h
#define _20_19_Nodes_QueueADT_h


//exception for when you try to pop an empty stack
class DequeueFromEmptyException : std::exception {};

class QueueADT {
    
public:
        
    //returns true if stack has no items, false otherwise
    virtual bool isEmpty()=0;
    
    //adds one item to the top of the queue
    virtual int enqueue(std::string nameIn)=0;
    
    //removes one item from the top of the stack and returns it
    virtual std::string dequeue(int idNumberIn)=0;
    
    //returns the size of the queue
    virtual int sizeOf()=0;
    
    //returns all of the contents of the queue
    virtual std:: string toString()=0;
    
    //returns the info of a person in a certain spot
    virtual std:: string get(int index)=0;
    
    //default destructor, declared virtual to ensure that child destructors are called
    virtual ~QueueADT(){};
};

#endif
