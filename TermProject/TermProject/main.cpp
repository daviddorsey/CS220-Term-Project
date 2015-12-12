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
#include "TextUI.h"
#include "Game.h"


int main(int argc, const char * argv[]) {
    
    
    //TextUI();
    
    Game* TestGame = new Game(250,59.99,"Fallout4","Action","M",false, "Jimmy");
    Console* TestConsole = new Console(400,399.99,"PS4","default","Sony",24,false);
    Accessory* TestAccessory = new Accessory(25,39.99,"WiiFitBalanceBoard","Wii",true,24);
    Game* TestGame2 = new Game(300,50,"Splatoon","Colorful","T",false, "David");
    Console* TestConsole2 = new Console(500,289.99,"XBOXone","","Microsoft",18,false);
    Accessory* TestAccessory2 = new Accessory(15,40,"Wireless Headset","Xbox",true,12);


    
    Inventory* testInventory = new Inventory();
//    
//    testInventory->fromFile("game.txt");
//    testInventory->fromFile("console.txt");
//    testInventory->fromFile("accessory.txt");

    
    Game* TestG = new Game(250,59.99,"Fallout3","Action","M",false, "Jimmy");
    Console* TestC = new Console(400,399.99,"PS3","default","Sony",24,false);
    Accessory* TestA = new Accessory(25,39.99,"WiiFit","Wii",true,24);
    Game* TestG2 = new Game(300,50,"Sp","Colorful","T",false, "David");
    Console* TestC2 = new Console(500,289.99,"XBOX","","Microsoft",18,false);
    Accessory* TestA2 = new Accessory(15,40,"Wireless Head","Xbox",true,12);
    
    testInventory->addGameStock(TestGame2);
    testInventory->addGameStock(TestGame);
    testInventory->addAcessStock(TestAccessory2);
    testInventory->addConsoleStock(TestConsole2);
    testInventory->addConsoleStock(TestConsole);
    testInventory->addAcessStock(TestAccessory);

    testInventory->addGameStock(TestG);
    testInventory->addConsoleStock(TestC);
    testInventory->addAcessStock(TestA2);
    testInventory->addGameStock(TestG2);
    testInventory->addConsoleStock(TestC2);
    testInventory->addAcessStock(TestA);
    
    
    std::cout<<testInventory->getListofGame();
    std::cout<<testInventory->getListofConsole();
    std::cout<<testInventory->getListofAccess();


//
//    std::cout << "\n\n\nTESTING SEARCHING\n\n\n";
////    
//    std::cout<<testInventory->checkGameStock("fallout4new")<<"\n\n";
//    std::cout<<testInventory->checkConsoleStock("PS4 Standard new")<<"\n\n";
//    std::cout<<testInventory->checkAcessStock("wiifitbalanceboardwiiused")<<"\n\n";
//    
    
////
//    testInventory->toFile("game.txt");
//    testInventory->toFile("console.txt");
//    testInventory->toFile("accessory.txt");
    
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
