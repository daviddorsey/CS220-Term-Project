//
//  Item.cpp
//  TermProject
//
//  Created by David Dorsey on 12/8/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include "Item.h"
#include <iostream>


//helper function for formatting search name
std::string searchFormat(std::string s){
    std::locale loc;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            s[i] = std::tolower(s[i], loc);
        }
        
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

//overloaded constructor with default values
Item::Item(int stockIn, float priceIn, std::string titleIn, bool preownedIn){
    numInStock = stockIn;
    price = priceIn;
    title = titleIn;
    preowned = preownedIn;
    searchName = searchFormat(title)+std::to_string(preowned);
}

//buys more copies of the console to put on the shelves
void Item::buy(int numCopies){
    numInStock += numCopies;
}

//sells console(s) to a customer in the store
void Item::sell(int numCopies){
    if(numCopies > numInStock){
        std::cout << "\n Not enough items in stock. Would you like to buy all " + std::to_string(numInStock) + " available items? Type 'y' to purchase.\n";
        std::string selection;
        std::cin >> selection;
        if(selection == "y"){
            numInStock = 0;
            std::cout << "Sold " + title + " x " + std::to_string(numCopies) + ".\n" + "Thank you for your purchase!\n";
        }
        else{
            return;
        }
    }
    else{
        numInStock -= numCopies;
        std::cout << "Sold " + title + " x " + std::to_string(numCopies) + ".\n" + "Thank you for your purchase!\n";
    }

}

//takes a console off the shelves so it's no longer available for purchase
void Item::remove(){
    numInStock = 0;
}

void Item::setPrice(float priceIn){  price = priceIn;  }
std::string Item::getTitle(){  return title;  }
void Item::setTitle(std::string titleIn){  title = titleIn;  }
bool Item::getPreowned(){  return preowned;  }
std::string Item::getSearchName(){  return searchName;  }

//formats an object's information in a readable string
std::string Item::toString(){
    if(preowned){
        return title + " (New): " + std::to_string(numInStock) + " in stock, at $" + std::to_string(price) + ".\n";
    }
    return title + " (Used): " + std::to_string(numInStock) + " in stock, at $" + std::to_string(price) + ".\n";
}
