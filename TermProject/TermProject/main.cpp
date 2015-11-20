//
//  main.cpp
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include <iostream>
#include "Inventory.h"

int main(int argc, const char * argv[]) {
    
    inventory* gameStoreInventory = new inventory();
    
    gameStoreInventory->additem(20, "Xbox One", 300, " ","Microsoft");
    
    std:: cout << gameStoreInventory->checkStock(1, "Xbox One");
    
    gameStoreInventory->sell(1, "Xbox One", 2);
    
    std:: cout << gameStoreInventory->checkStock(1, "Xbox One");
    
    gameStoreInventory->restock(1, "Xbox One", 100);
    
    std:: cout << gameStoreInventory->checkStock(1, "Xbox One");
    
    
    

    return 0;
}
