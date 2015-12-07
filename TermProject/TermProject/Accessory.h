//
//  Accessory.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Accessory__
#define __TermProject__Accessory__

#include <stdio.h>
#include "ItemADT.h"
#include <iostream>

class Accessory : public ItemADT{
    
private:
    int numInStock;
    float price;
    std:: string title;
    std:: string consoleTo;
    int warranty;
    bool preOwned;

public:
    //Constructor
    Accessory(int stockIn, float priceIn, std::string titleIn, std::string consoleToIn, bool preOwnedIn, int warrantyIn);
    
    //Destructor
    ~Accessory();
    
    //Allows the store to restock the accessory
    void buy(int numOfCopies);
    
    //Allows the store to sell the accessory
    void sell(int numOfCopies);
    
    //Allows the store to set the price of the accessory
    void setPrice(float priceIn);
    
    //returns all of the information the acessory has
    std::string toString();
    
};
#endif /* defined(__TermProject__Accessory__) */
