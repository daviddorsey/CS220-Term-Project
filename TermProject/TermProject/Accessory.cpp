//
//  Accessory.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include "Accessory.h"

//Constructor
Accessory:: Accessory(int stockIn, float priceIn, std::string titleIn, std::string consoleToIn, bool preOwnedIn, int warrantyIn){
    
    numInStock = stockIn;
    price = priceIn;
    title = titleIn;
    consoleTo = consoleToIn;
    preOwned = preOwnedIn;
    warranty = warrantyIn;
    
}

//Destructor
Accessory:: ~Accessory(){
    
}

//Input: number of copies user bought
//Output: nothing
//Purpose: Allows the store to restock the accessory
void Accessory:: buy(int numOfCopies){
    numInStock +=numOfCopies;
}

//Input: number of copies user sold
//Output: nothing
//Purpose: Allows user to sell the accessory
void Accessory:: sell(int numOfCopies){
     numInStock -=numOfCopies;
}

//Input: price of the item
//Output: nothing
//Purpose: Allows the store to set the price of the accessory
void Accessory:: setPrice(float priceIn){
    price = priceIn;
}

//Input: nothing
//Output: a stign version of all the data for the accessory
//Purpose: returns all of the information the acessory has
std::string Accessory:: toString(){
    
    std:: string result = "Title: " + title + "\n";
    result += "Price " + std::to_string(price) + "\n";
    result += std::to_string(numInStock) + " copies in stock \n";
    result += "This accessory goes with " + title + "\n";
    result += "It has a waranty of " + std::to_string(warranty) + "\n";
    if (preOwned) {
        result += "Condition: Preowned \n";
    }
    else{
        result += "Condition: New \n";
    }
    
    return result;
}
