//
//  Queue.cpp
//  Lab6
//
//  Created by Danny Kustin on 10/8/15.
//  Copyright (c) 2015 Daniel Kustin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Queue.h"
#include "QueueADT.h"

//Default Constructor
//Input: nothing
//Output nothing
//Purpose: Creates and empty queue
Queue:: Queue(){
    arr = new ItemType[1];
    size = 1;
    servingNumber = 0;
    timer = 3;
}

//Constructor with queue to enter
//Input: queue to be used
//Output nothing
//Purpose: Creates a filled queue
Queue:: Queue(const Queue& queueToCopy){
    size = queueToCopy.size;
    servingNumber = queueToCopy.servingNumber;
    ItemType* holdArray = new ItemType[size];
    timer = queueToCopy.timer + 3;
    for (int i = 0; i < size; i++) {
        holdArray[i] = queueToCopy.arr[i];
    }
    delete[] arr;
    arr = holdArray;
    holdArray = nullptr;
}

//Destructor
//Input: nothing
//Output nothing
//Purpose: code that needs to be destroyed before queue is
Queue:: ~Queue(){
    delete[] arr;
    arr = nullptr;
    
}

//Input: nothing
//Output nothing
//Purpose: Sees if the queue is empty
bool Queue:: isEmpty(){
    timer++;
    if (servingNumber == 0) {
        return true;
    }
    else{
        return false;
    }
}
//Input: item that is to be added
//Output: nothing
//Purpose: Adds one item to the back of the Queue
void Queue:: enqueue(ItemType newItem){
    timer +=2;
    if(servingNumber >= size ){
        size*=2;
        ItemType* newArr = new ItemType[size];
        for (int i = 0; i < servingNumber; i++) {
            newArr[i] = arr[i];
            timer++;
        }
        delete[] arr;
        arr = newArr;
        newArr = nullptr;
        timer +=5;
    }
    arr[servingNumber] = newItem;
    servingNumber++;
    timer++;
}

//Input: nothing
//Output nothing
//Purpose: Removes one item from the front of the Queue and returns it
ItemType Queue:: dequeue(){
    timer++;
    if (isEmpty()) {
        throw DequeueFromEmptyException();
    }
    ItemType firstPerson = arr[0];
    timer++;
    for (int i = 1; i < servingNumber; i++) {
        arr[i-1] = arr[i];
        timer++;
    }
    //std::cout << servingNumber <<  "->" << arr[servingNumber] << std::endl;
    servingNumber--;
    timer++;
    return firstPerson;
}

//Input: nothing
//Output: nothing
//Purpose: keeps track of how much memory the object is using
int Queue:: calcMemUsage(){
    return sizeof(size) + sizeof(servingNumber) + sizeof(timer) + sizeof(arr) + ( sizeof(*arr) * size);
}

//Input: nothing
//Output: nothing
//Purpose: keeps track of how many lines of code the object is using
int Queue:: getElapsedTime(){
    return timer;
}

//Input: nothing
//Output: size of queue
//Purpose: returns the size of the queue
int Queue:: sizeOf(){
    return size;
}





