//
//  ItemADT.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef TermProject_ItemADT_h
#define TermProject_ItemADT_h

class ItemADT{
    
public:
    
    //Restocks an item by buying more, reducing revenue for the day
    //int numCopies - number of items that the store is buying
    //int buyPrice - price of each item
    virtual void buy(int numCopies) = 0;
    
    //Sells one copy of an item, reducing that item's stock by one and increasing revenue for the day
    virtual void sell(int numCopies) = 0;
    
    //Removes an item from the shelves, setting numInStock to 0
    virtual void remove() = 0;
    
    //Changes the price of an item
    //float price - new price that the item will be set to
    virtual void setPrice(float price) = 0;
    
};

#endif

