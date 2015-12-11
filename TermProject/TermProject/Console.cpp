//
//  Console.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include "Console.h"
#include <iostream>

//helper function for formatting search name
std::string Console::searchFormat(std::string s){
    std::locale loc;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            s[i] = std::tolower(s[i], loc);
        }
        
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

Console::Console(int stockIn, float priceIn, std::string titleIn, std::string editionIn, std::string manufacturerIn, int warrantyIn, bool preownedIn){
    numInStock = stockIn;
    price = priceIn;
    title = titleIn;
    edition = editionIn;
    manufacturer = manufacturerIn;
    warranty = warrantyIn;
    preowned = preownedIn;
    searchName = searchFormat(title)+searchFormat(edition)+"new";
    if(preowned)
        searchName = searchFormat(title)+searchFormat(edition)+"used";
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

void Console::remove(){
    numInStock = 0;
}

void Console::setNumInStock(int stockIn){  numInStock = stockIn;  }
int Console::getNumInStock(){  return numInStock;  }
void Console::setPrice(float priceIn){  price = priceIn;  }
float Console::getPrice(){  return price;  }
void Console::setTitle(std::string titleIn){  title = titleIn;  }
std::string Console::getTitle(){  return title;  }
void Console::setManufacturer(std::string manufacturerIn){  manufacturer = manufacturerIn;  }
std::string Console::getManufacturer(){  return manufacturer;  }
void Console::setEdition(std::string editionIn){  edition = editionIn;  }
std::string Console::getEdition(){  return edition;  }
void Console::setWarranty(int warrantyIn){  warranty = warrantyIn;  }
int Console::getWarranty(){  return warranty;  }
void Console::setPreowned(bool preownedIn){  preowned = preownedIn;  }
bool Console::getPreowned(){  return preowned;  }
void Console::setSearchName(std::string searchNameIn){  searchName = searchNameIn;  }
std::string Console::getSearchName(){  return searchName;  }

std::string Console::toString(){
    if(preowned){
        return title + " - " + edition + " edition (Used): " + std::to_string(numInStock) + " in stock, at $" + std::to_string(price) + ". Manufactured by " + manufacturer + ". Available " + std::to_string(warranty) + " month warranty.\n";
    }
    return title + " - " + edition + " edition (New): " + std::to_string(numInStock) + " in stock, at $" + std::to_string(price) + ". Manufactured by " + manufacturer + ". Available " + std::to_string(warranty) + " month warranty.\n";
}

std::string Console::fileFormat(){
    return title + "," + std::to_string(price) + "," + std::to_string(numInStock) + "," + std::to_string(preowned) + "," + edition + "," + manufacturer + "," + std::to_string(warranty);
}