//
//  ItemContainer.h
//  TermProject
//
//  Created by Jimmy Wang on 12/9/15.
//  Copyright © 2015 David Dorsey. All rights reserved.
//


//TODO 
#ifndef itemContainer_h
#define itemContainer_h

#include <iostream>
#include "ItemADT.h"

class ItemContainer {
private:
    int fillIndex;
    int inPoint;
    int size;
    ItemADT** dict;
    bool search(std::string searchName);
    bool linSearch(std::string searchName);
    bool binSearch(std::string searchName);
    void doubleSize();
    void shiftOrderRight(ItemADT* itemToAdd);
    void shiftOrderLeft();
    
public:
    ItemContainer();
//    ItemContainer(const ItemContainer& ItemContainerToCopy);
    void add(ItemADT* itemToAdd);
    void remove(std::string searchName);
    ItemADT* get(std::string searchName);
    ItemADT* get(int accIndex);
    bool contains(std::string searchName);
    //Destructor
    ~ItemContainer();
    
};


#endif /* itemContainer_h */
