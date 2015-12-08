//
//  Queue.cpp
//  Lab6
//
//  Created by Danny Kustin on 10/8/15.
//  Copyright (c) 2015 Daniel Kustin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "QueueADT.h"
#include "Queue.h"
#include "Node.h"

//Default Constructor
//Input: nothing
//Output nothing
//Purpose: Creates and empty queue
Queue:: Queue(){
    first = nullptr;
    last = nullptr;
    size = 0;
    useableIdNumber = 0;
}

//Constructor with queue to enter
//Input: queue to be used
//Output nothing
//Purpose: Creates a filled queue
Queue::Queue(Queue* queueToCopy){
    size = queueToCopy->size;
    first = queueToCopy->first;
    last = queueToCopy->last;
    useableIdNumber = queueToCopy->useableIdNumber;
    for (int i = 1; i < size; i++) {
        std::string newName = first->getName();
        int newIdNumber = first->getIdNumber();
        Node* newPerson = new Node(newName, newIdNumber);
        first = first->getNext();
        newPerson->setNext(first);
    }
}

//Destructor
//Input: nothing
//Output nothing
//Purpose: code that needs to be destroyed before queue is
Queue:: ~Queue(){
    Node* next = first->getNext();
    delete first;
    for (int i = 1; i < size; i++) {
        next = next->getNext();
        delete next;
    }
}

//Input: nothing
//Output nothing
//Purpose: Sees if the queue is empty
bool Queue:: isEmpty(){
    if (size == 0) {
        return true;
    }
    else{
        return false;
    }
}
//Input: item that is to be added
//Output: nothing
//Purpose: Adds one item to the back of the Queue
void Queue:: enqueue(std::string nameIn){
    useableIdNumber++;
    Node* newNode = new Node(nameIn, useableIdNumber);
    if ( isEmpty() ) {
        first = newNode;
        last = newNode;
        size++;
        return;
    } else {
        last->setNext(newNode);
        last = newNode;
        size++;
    }
}

//Input: nothing
//Output nothing
//Purpose: Removes one item from the front of the Queue and returns it
std::string Queue:: dequeue(int idNumber){
    Node* before = nullptr;
    Node* middle = first;
    Node* after = middle->getNext();
    for (int i = 0; i < size; i++) {
        if( idNumber == middle->getIdNumber() ){
            
            std:: string removedOneName = middle->getName();
            int removedOneIdNumber = middle->getIdNumber();
            std:: string removedOne = removedOneName + " ID Number: " + std::to_string(removedOneIdNumber);
            
            if(before == nullptr){
                first = after;
            }
            else{
                before->setNext(after);
            }
            size--;
            return removedOne;
        }
        before = middle;
        middle = after;
        after = after->getNext();
    }
    return "No one with that ID Number found";
    
}

//Input: nothing
//Output: size of queue
//Purpose: returns the size of the queue
int Queue:: sizeOf(){
    return size;
}

//Input: nothing
//Output: string of the queue
//Purpose: to get the content of the whole queue
std:: string Queue:: toString(){
    std:: string content;
    Node* next = first;
    for ( int i = 0; i < size; i++){
        content += next->getName() + " ID Number: " + std::to_string( next->getIdNumber() ) + ", ";
        next = next->getNext();
    }
    return content;
}

//Input: index of person you want to get
//Output: string of the person at that index
//Purpose: to get the a single person in the list
std:: string Queue:: get(int index){
    Node* next = first;
    for ( int i = 0; i < index; i++){
        next = next->getNext();
    }
    std:: string info = next->getName() + " ID Number: " + std::to_string( next->getIdNumber() );
    return info;
}





