//
//  Inventory.h
//  TermProject
//
//  Created by Jimmy Wang on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Inventory__
#define __TermProject__Inventory__

#include <stdio.h>
#include <iostream>
#include "itemADT.h"
#include "ItemContainer.h"
#include "Console.h"
#include "Game.h"
#include "Accessory.h"
#include "Item.h"

class Inventory{
    
private:
    int numGames;
    int numConsoles;
    int numAccessories;
    ItemContainer acessStock;
    ItemContainer consoleStock;
    ItemContainer gameStock;
    std::string toSearchFormat(std::string itemName);
    
public:
    Inventory();
    Inventory(const Inventory &inventoryToCopy);
    
    void addAcessStock(Accessory* itemToAdd);
    void addGameStock(Game* itemToAdd);
    void addConsoleStock(Console* itemToAdd);
    
    std::string checkAcessStock(std::string title);
    std::string checkGameStock(std::string title);
    std::string checkConsoleStock(std::string title);
    
    std::string  restockAcess(std::string title, int numCopies);
    std::string  restockGame(std::string title, int numCopies);
    std::string  restockConsole(std::string title, int numCopies);
    
    std::string  sellAcess(std::string title, int sellAmount);
    std::string  sellGame(std::string title, int sellAmount);
    std::string  sellConsole(std::string title, int sellAmount);

    void  removeAcess(std::string title);
    void  removeGame(std::string title);
    void  removeConsole(std::string title);
    
    void fromFile(std::string filename);
    void toFile(std::string filename);
    
    
    
};

#endif /* defined(__TermProject__Inventory__) */
