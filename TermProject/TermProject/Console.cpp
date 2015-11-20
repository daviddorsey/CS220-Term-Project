//
//  Console.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include "Console.h"
#include <iostream>

Console::Console(int stockIn, float priceIn, std::string titleIn, std::string editionIn, std::string manufacturerIn, int warrantyIn, bool preownedIn){
    numInStock = stockIn;
    price = priceIn;
    title = titleIn;
    edition = editionIn;
    manufacturer = manufacturerIn;
    warranty = warrantyIn;
    preowned = preownedIn;
}

void Console::buy(int numCopies){
    numInStock += numCopies;
}

void Console::sell(int numCopies){
    if(numCopies > numInStock){
        std::cout << "\n Not enough consoles in stock. Would you like to buy all " + std::to_string(numInStock) + " available consoles? Type 'y' to purchase.\n";
        std::string selection;
        std::cin >> selection;
        if(selection == "y"){
            numInStock = 0;
            std::cout << "Thank you for you purchase!";
        }
        else{
            return;
        }
    }
    else{
        numInStock -= numCopies;
        std::cout << "Thank you for you purchase!";
    }
}

void Console::remove(){
    numInStock = 0;
}

void Console::setPrice(float priceIn){  price = priceIn;  }
std::string Console::getTitle(){  return title;  }
void Console::setTitle(std::string titleIn){  title = titleIn;  }
std::string Console::getEdition(){  return edition;  }
bool Console::getPreowned(){  return preowned;  }

std::string Console::toString(){
    if(preowned){
        return title + " - " + edition + " edition (Used): " + std::to_string(numInStock) + "in stock, at $" + std::to_string(price) + ". Manufactured by " + manufacturer + ". Available " + std::to_string(warranty) + " month warranty.";
    }
    return title + " - " + edition + " edition (New): " + std::to_string(numInStock) + "in stock, at $" + std::to_string(price) + ". Manufactured by " + manufacturer + ". Available " + std::to_string(warranty) + " month warranty.";
}