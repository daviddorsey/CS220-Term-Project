//
//  Queue.h
//  Lab6-StacksAndQueues
//
//  Created by Toby Dragon on 10/8/15.
//  Copyright (c) 2015 Toby Dragon. All rights reserved.
//

#ifndef __Lab6_StacksAndQueues__Queue__
#define __Lab6_StacksAndQueues__Queue__

#include "GenericItemType.h"
#include "QueueADT.h"

class Queue : public QueueADT {
private:
    ItemType* arr;
    int size;
    int servingNumber;
    int timer;
    
public:
    //Constructor: creates a new, empty Queue
    Queue();
    //Copy Constructor: makes a new deep copy of the Queue parameter
    Queue(const Queue& queueToCopy);
    //Destructor
    ~Queue();
    
    //returns true if Queue has no items, false otherwise
    bool isEmpty();
    //adds one item to the back of the Queue
    void enqueue(ItemType newItem);
    //removes one item from the front of the Queue and returns it
    ItemType dequeue();
    
    //returns the total number of bytes of memory this object is using
    int calcMemUsage();
    //returns the total amount of time used by this object (number of lines of code executed)
    int getElapsedTime();
    
    //returns the size of the queue
    int sizeOf();
};

#endif /* defined(__Lab6_StacksAndQueues__Queue__) */
