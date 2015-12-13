//
//  Item.h
//  TermProject
//
//  Created by David Dorsey on 12/8/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Item__
#define __TermProject__Item__

#include <stdio.h>
#include <string>
#include "ItemADT.h"

class Item : public ItemADT{
    
private:
    //number of a specific console that the store has in stock
    int numInStock;
    //the price of each console
    float price;
    //name of the console
    std::string title;
    //stores whether the console is new or used
    bool preowned;
    //unique name used for searching in the inventory
    std::string searchName;
    
public:
    //overloaded constructor with default values
    Item(int stockIn=0, float priceIn=0, std::string titleIn="", bool preownedIn=false);
    
    //buys more copies of the console to put on the shelves
    virtual void buy(int numCopies);
    
    //sells console(s) to a customer in the store
    virtual void sell(int numCopies);
    
    //takes a console off the shelves so it's no longer available for purchase
    virtual void remove();
    
    //changes the numInStock of the console
    virtual void setNumInStock(int stockIn);
    
    //returns the console's price
    virtual int getNumInStock();
    
    //changes the price of the console
    virtual void setPrice(float priceIn);
    
    //returns the console's price
    virtual float getPrice();
    
    //changes the console's title
    virtual void setTitle(std::string titleIn);
    
    //returns the console's title
    virtual std::string getTitle();
    
    //sets whether a console is preowned
    virtual void setPreowned(bool preownedIn);
    
    //returns the console's preowned status - true if it was preowned, false if it is new
    virtual bool getPreowned();

    //formats an object's information in a readable string
    virtual std::string toString();
    
    //creates a string with all of the contents for the game reordered for file writing
    virtual std::string fileFormat() = 0;
    
    //sets the console's search name
    virtual void setSearchName(std::string searchNameIn);
    
    //returns the item's search name
    virtual std::string getSearchName();
    
    virtual void comeToStock()=0;

    
//    virtual ~Item(){};
};


#endif /* defined(__TermProject__Item__) */
