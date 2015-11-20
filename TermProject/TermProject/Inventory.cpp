//
//  Inventory.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include "Inventory.h"
#include "Console.h"

inventory::inventory(){
    gameSize =10;
    gameIndex=0;
    acessSize=10;
    acessIndex=0;
    consoleSize = 10;
    consoleIndex=0;
    gameStock = new ItemADT*[gameSize];
    consoleStock = new Console*[consoleSize];
    acessStock = new ItemADT*[acessSize];
    
};

void inventory::additem(int numinStock, std::string title, float price, std::string edition, std::string manufacturer, int warranty, bool preowned){
    
    if(consoleIndex<consoleSize){
        consoleStock[consoleIndex]= new Console(numinStock,price,title,edition,manufacturer,warranty,preowned);
        consoleIndex++;
    }
    std:: cout << "Item added: " + consoleStock[consoleIndex-1]->toString();
};

void inventory::restock(int choice, std::string title, int numCopies){
    switch (choice) {
        case 0:
            for(int i=0; i<gameIndex;i++){
//                if(gameStock[i]->getTitle() == title){
//                    gameStock[i]->buy(numCopies);
//                }
            }
            break;
        case 1:
            for(int i=0; i<consoleIndex;i++){
                if(consoleStock[i]->getTitle() == title){
                    consoleStock[i]->buy(numCopies);
                }
            }
            break;
        case 2:
            for(int i=0; i<acessIndex;i++){
//                if(acessStock[i]->getTitle() == title){
//                    acessStock[i]->buy(numCopies);
//                }
            }
            break;
        default:
            break;
    }
}

void inventory::sell(int choice,std::string title, int amount){
    switch (choice) {
        case 0:
            for(int i=0; i<gameIndex;i++){
//                if(gameStock[i]->getTitle() == title){
//                    gameStock[i]->sell(numCopies);
//                }
            }
            break;
        case 1:
            for(int i=0; i<consoleIndex;i++){
                if(consoleStock[i]->getTitle() == title){
                    consoleStock[i]->sell(amount);
                }
            }
            break;
        case 2:
            for(int i=0; i<acessIndex;i++){
//                if(acessStock[i]->getTitle() == title){
//                    acessStock[i]->sell(numCopies);
//                }
            }
            break;
        default:
            break;
    }

};

std::string inventory::checkStock(int choice,std::string title){
    std::string temp;
    switch (choice) {
        case 0:
            for(int i=0; i<gameIndex;i++){
//                if(gameStock[i]->getTitle() == title){
//                    std::cout<<gameStock[i]->toString();
//                }
            }
            break;
        case 1:
            for(int i=0; i<consoleIndex;i++){
                if(consoleStock[i]->getTitle() == title){
                    temp = consoleStock[i]->toString();
                }
            }
            break;
        case 2:
            for(int i=0; i<acessIndex;i++){
//                if(acessStock[i]->getTitle() == title){
//                    std::cout<<acessStock[i]->toString();
//                }
            }
            break;
        default:
            break;
    }
    return temp;
}
