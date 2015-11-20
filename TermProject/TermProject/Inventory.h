//
//  Inventory.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Inventory__
#define __TermProject__Inventory__

#include <stdio.h>
#include <iostream>
#include "itemADT.h"
#include "Console.h"

class inventory{
    
private:
    ItemADT** gameStock;
    int gameIndex;
    int gameSize;
    Console** consoleStock;
    int consoleIndex;
    int consoleSize;
    ItemADT** acessStock;
    int acessIndex;
    int acessSize;

public:
    inventory();
    void additem(int numinStock= 0, std::string title = "null", float price =0, std::string edition = "stander", std::string manufacturer = "unknow", int warranty = 12, bool preowned = false);
    void restock(int choice,std::string title, int numCopies);
    void sell(int choice,std::string title, int amount);
    void remove(std::string title);
    std::string checkStock(int choice, std::string title);
    
    

};

#endif /* defined(__TermProject__Inventory__) */
