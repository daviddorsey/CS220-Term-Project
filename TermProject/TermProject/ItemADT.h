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
    virtual void setPrice(float priceIn) = 0;
    
    //returns the console's title
    virtual std::string getTitle()= 0;
    
    //changes the console's title
    virtual void setTitle(std::string titleIn)= 0;
    
    //returns the console's preowned status - true if it was preowned, false if it is new
    virtual bool getPreowned()= 0;
    
    virtual int getNumInStock()=0;
    
    //formats an object's information in a readable string
    virtual std::string toString()= 0;
    
    //creates a string with all of the contents for the game reordered for file writing
    virtual std::string fileFormat() = 0;
    
    //returns the item's search name
    virtual std::string getSearchName()= 0;
    
    virtual void comeToStock()=0;
    
    virtual bool getPreorderStatus()=0;
    
    virtual int preOrder(std:: string name) =0;
    
    virtual std::string removePreOrder(int idNumber)=0;
    
    virtual ~ItemADT(){};

};

#endif

