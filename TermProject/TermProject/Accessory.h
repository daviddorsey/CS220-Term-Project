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
#include "Item.h"
#include <iostream>

class Accessory : public Item{
    
private:
    int numInStock;
    float price;
    std:: string title;
    std:: string consoleTo;
    int warranty;
    bool preowned;
    std:: string searchName;
    std::string searchFormat(std::string s);

public:
    //Constructor
    Accessory(int stockIn, float priceIn, std::string titleIn, std::string consoleToIn, bool preownedIn, int warrantyIn);
    
    //Allows the store to restock the accessory
    void buy(int numOfCopies);
    
    //Allows the store to sell the accessory
    void sell(int numOfCopies);
    
    //Allows the store to set the price of the accessory
    void setPrice(float priceIn);
    
    //returns all of the information the acessory has
    std::string toString();
    
    //creates a string with all of the contents for the game reordered for file writing
    std::string fileFormat();
    
    //Getters
    std:: string getTitle();
    std:: string getConsoleTo();
    int getWarranty();
    std:: string getSearchName();
    int getNumInStock();
    
    
    //Setters
    void setConsoleTo(std:: string consoleToIn);
    void setWarranty(int warrantyIn);
    
    void comeToStock(){};
    bool getPreorderStatus(){return 0;};
    int preOrder(){return 0;};
    int preOrder(std:: string name){return 0;};
    std::string removePreOrder(int idNumber){return 0;};



    
};
#endif /* defined(__TermProject__Accessory__) */
