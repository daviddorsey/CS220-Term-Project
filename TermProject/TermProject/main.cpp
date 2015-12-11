//
//  main.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include <iostream>
#include "Inventory.h"
#include "ItemADT.h"

int main(int argc, const char * argv[]) {
    
    
    
    Console* TestConsole = new Console(10,60,"testPS4","","Sony",1,false);
   
    
    Inventory* testInventory = new Inventory();
    
    testInventory->addConsoleStock(TestConsole);
    
    std::cout<<testInventory->checkConsoleStock("TestPS4 new");
    
    /*
    inventory* gameStoreInventory = new inventory();
    std::cout << "~Prototype testing for Video Game Inventory system~\n\n";
    
    std::cout << "Testing additem...\n";
    gameStoreInventory->additem(20, "Xbox One", 300, "default","Microsoft");
    std:: cout << std::endl << gameStoreInventory->checkStock(1, "Xbox One") << std::endl;
    
    std::cout << "Testing sell...\n";
    gameStoreInventory->sell(1, "Xbox One", 2);
    std:: cout << std::endl << gameStoreInventory->checkStock(1, "Xbox One") << std::endl;
    
    std::cout << "Testing restock...\n";
    gameStoreInventory->restock(1, "Xbox One", 100);
    std:: cout << std::endl << gameStoreInventory->checkStock(1, "Xbox One") << std::endl;
    */
    

    return 0;
}
