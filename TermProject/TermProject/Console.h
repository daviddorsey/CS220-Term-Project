//
//  Console.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Console__
#define __TermProject__Console__

#include <stdio.h>
#include <string>
#include "Item.h"

class Console : public Item{
    
private:
    //number of a specific console that the store has in stock
    int numInStock;
    //the price of each console
    float price;
    //name of the console
    std::string title;
    //name of the edition if it is a special edition, otherwise will just be "default"
    std::string edition;
    //name of the company that makes the console
    std::string manufacturer;
    //number of months that a warranty is available for
    int warranty;
    //stores whether the console is new or used
    bool preowned;
    //unique name used for searching in the inventory
    std::string searchName;
    std::string searchFormat(std::string s);
    
public:
    //overloaded constructor with default values
    Console(int stockIn=0, float priceIn=0, std::string titleIn="", std::string editionIn="", std::string manufacturerIn="", int warrantyIn=0, bool preownedIn=false);
    
    //buys more copies of the console to put on the shelves
    void buy(int numCopies);
    
    //sells console(s) to a customer in the store
    void sell(int numCopies);
    
    //takes a console off the shelves so it's no longer available for purchase
    void remove();
    
    //formats an object's information in a readable string
    std::string toString();
    
    void setNumInStock(int stockIn);
    int getNumInStock();
    void setPrice(float priceIn);
    float getPrice();
    void setTitle(std::string titleIn);
    std::string getTitle();
    void setManufacturer(std::string manufacturerIn);
    std::string getManufacturer();
    void setEdition(std::string editionIn);
    std::string getEdition();
    void setWarranty(int warrantyIn);
    int getWarranty();
    void setPreowned(bool preownedIn);
    bool getPreowned();
    void setSearchName(std::string searchNameIn);
    std::string getSearchName();
    
    std::string getSearchName();

    
};

#endif /* defined(__TermProject__Console__) */
