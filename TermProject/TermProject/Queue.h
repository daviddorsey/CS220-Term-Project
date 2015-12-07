//
//  Queue.h
//  Lab6-StacksAndQueues
//
//  Created by Toby Dragon on 10/8/15.
//  Copyright (c) 2015 Toby Dragon. All rights reserved.
//

#ifndef __Lab6_StacksAndQueues__Queue__
#define __Lab6_StacksAndQueues__Queue__

#include "QueueADT.h"
#include "Node.h"

class Queue : public QueueADT {
private:
    Node* first;
    Node* last;
    int size;
    int useableIdNumber;
    
public:
    //Constructor: creates a new, empty Queue
    Queue();
    
    //Copy Constructor: makes a new deep copy of the Queue parameter
    Queue(Queue* queueToCopy);
    
    //Destructor
    ~Queue();
    
    //returns true if Queue has no items, false otherwise
    bool isEmpty();
    
    //adds one item to the back of the Queue
    void enqueue(std::string nameIn);
    
    //removes one item from the front of the Queue and returns it
    std::string dequeue(int idNumberIn);
    
    //returns the size of the queue
    int sizeOf();
    
    //returns all of the contents of the queue
    std:: string toString();
    
    //returns the info of a person in a certain spot
    std:: string get(int index);
};

#endif /* defined(__Lab6_StacksAndQueues__Queue__) */
