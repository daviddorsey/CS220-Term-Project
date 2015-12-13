//
//  TextUI.cpp
//  TermProject
//
//  Created by Jimmy Wang on 12/11/15.
//  Copyright © 2015 David Dorsey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Inventory.h"
#include "ItemADT.h"

void TextUI(){
    Inventory* inv = new Inventory();
    bool shutdown = false;

    //read from file
    //    inv->fromFile("game.txt");
    //    inv->fromFile("console.txt");
    //    inv->fromFile("accessory.txt");
    
    std:: cout << "Welcome to the GameStore Inventory Manage System " << std:: endl;
    while ( !shutdown ){
        std:: string prompt;
        int userInput;
        std::string userInputS;
        std:: string helpInfo;
        std:: string searchName;
        int IDnumber;
        prompt = "\nSelect to Continue (Use number associated with choice)\n"
        "1) Add New Item\n"
        "2) Sell Item\n"
        "3) Remove Preorder\n"
        "4) Restock Item\n"
        "5) Check In Stock Item\n"
        "6) Modify In Stock Item Data\n"
        "7) Helper\n"
        "8) Shut Down and Save Data\n";
        
        //prints the prompt
        std:: cout << prompt;
        std:: cin >> userInput;
        std::string itemType, title, condition, manufacturer, edition, consoleTo, publisher, rating, genre, preorderString;
        int quantity, warranty;
        float price;
        bool preorder;
        
        switch (userInput) {
                
            case 1:
                std::cout<<"\nAdd New Item\nIs the new item a (Use letter associated with the choice): \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
                std::cin >> itemType;
                if(itemType != "a" && itemType != "b" && itemType != "c"){
                    std::cout << "Invalid input.";
                    break;
                }
                std::cout << "Enter the name of the item you would like to add (without spaces): ";
                std::cin >> title;
                std::cout << "Enter the price per item (Do not include a '$'): ";
                std::cin >> price;
                std::cout << "New or used? ";
                std::cin >> condition;
                if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                    std::cout << "Invalid input.";
                    break;
                }
                std::cout << "How many would you like to add? ";
                std::cin >> quantity;
                if(quantity < 0){
                    std::cout << "Invalid input.";
                    break;
                }
                //brings in data members specific to game
                if(itemType == "a"){
                    std::cout << "Enter the genre of the game: ";
                    std::cin >> genre;
                    std::cout << "Enter the ESRB rating of the game (E, E10+, T, or M): ";
                    std::cin >> rating;
                    if(rating != "E" && rating != "E10+" && rating != "T" && rating != "M"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    std::cout << "Enter the publisher of the game: ";
                    std::cin >> publisher;
                    
                    std::cout << "Is the the game in a preorder state? (T / F): ";
                    std::cin >> preorderString;
                    
                    if(preorderString == "T" || preorderString == "t"){
                        preorder = true;
                    } else if (preorderString == "F" || preorderString == "f"){
                        preorder = false;
                    } else{
                        std::cout << "Invalid input.";
                        break;
                    }
                    
                    Game* g;
                    if(condition == "New" || condition == "new")
                        //
                        g = new Game(quantity, price, title, genre, rating, false, publisher, preorder);
                    else
                        g = new Game(quantity, price, title, genre, rating, true, publisher, preorder);

                    inv->addGameStock(g);
                }
                //brings in data members specific to console
                if(itemType == "b"){
                    std::cout << "Enter the edition of the console (If standard edition, enter \"standard\"): ";
                    std::cin >> edition;
                    std::cout << "Enter the manufacturer of the console: ";
                    std::cin >> manufacturer;
                    std::cout << "Enter the length of the warranty in months: ";
                    std::cin >> warranty;
                    if(warranty < 0){
                        std::cout << "Invalid input.";
                        break;
                    }
                    Console* c;
                    if(condition == "New" || condition == "new"){
                        c = new Console(quantity, price, title, edition, manufacturer, warranty, false);
                    }else{
                        c = new Console(quantity, price, title, edition, manufacturer, warranty, true);
                    }
                     inv->addConsoleStock(c);
                }
                //brings in data members specific to accessory
                if(itemType == "c"){
                    std::cout << "Enter the name console that this accessory is compatible with: ";
                    std::cin >> consoleTo;
                    std::cout << "Enter the length of the warranty in months: ";
                    std::cin >> warranty;
                    if(warranty < 0){
                        std::cout << "Invalid input.";
                        break;
                    }
                    Accessory* a;
                    if(condition == "New" || condition == "new")
                        a = new Accessory(quantity, price, title, consoleTo, false, warranty);
                    else
                        a = new Accessory(quantity, price, title, consoleTo, true, warranty);
                    inv->addAcessStock(a);
                    
                }
                
                std::cout << "Adding " << quantity << " " << condition << " " << title << "(s) at $" << price << " each.\n\n";
                break;
                
            case 2:
                std::cout<<"\nSell Item\nIs the item being sold a (Use letter associated with the choice): \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
                std::cin >> itemType;
                
                if(itemType != "a" && itemType != "b" && itemType != "c"){
                    std::cout << "Invalid input.";
                    break;
                }
                
                std::cout << "Enter the name of the item you would like to sell: ";
                std::cin >> title;
                
                //if the item is a game
                if(itemType == "a"){
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    searchName = title + condition;
                    
                    //checks if game is in preorder state
                    if( inv->getPreorderStatus(searchName) ){
                        std:: cout << "This game is currently in preorder status" << std::endl;
                        std:: cout << "Would you like to preorder the Game? ( Y/N )" << std::endl;
                        std:: cin >> userInputS;
                        if(userInputS != "y" && userInputS != "Y" && userInputS != "n" && userInputS != "N"){
                            std::cout << "Invalid input.";
                            break;
                        }
                        if (userInputS == "y" || userInputS == "Y") {
                            std:: cout << "What is the name would you like on the waiting list?" << std::endl;
                            std:: cin >> userInputS;
                            std:: cout << "The ID number related to this preorder is " + std::to_string (inv->preOrder(searchName, userInputS)) +". It is required to be taken off the preorder list.\n";
                            break;
                        }
                        else{
                            break;
                        }
                    } else{
                        std::cout << "How many would you like to sell? ";
                        std::cin >> quantity;
                        if(quantity < 0){
                            std::cout << "Invalid input.";
                            break;
                        }
                    
                        //checks number of copies
                        int numOfCopies = inv->getNumInStockGame(searchName);
                        
                        if ( numOfCopies < quantity){
                            std:: cout << "There are not enough copies in stock.\n";
                            break;
                        }else{
                          inv->sellGame(searchName, quantity);
                        }
                        break;
                    }
                }
                //if the item is a console
                if(itemType == "b"){
                    std::cout << "Enter the edition of the console (If standard edition, press Enter): ";
                    std::cin >> edition;
                    searchName = title + edition + condition;
                    
                    //checks number of copies
                    int numOfCopies = inv->getNumInStockConsole(searchName);
                    
                    if ( numOfCopies < quantity){
                        std:: cout << "There are not enough copies in stock.";
                        break;
                    }else{
                        inv->restockConsole(searchName, quantity);
                    }
                    
                }
                //if the item is an accessory
                if(itemType == "c"){
                    std::cout << "Enter the name of the console that this accessory is compatible with: ";
                    std::cin >> consoleTo;
                    searchName = title + consoleTo + condition;
                    
                    //checks number of copies
                    int numOfCopies = inv->getNumInStockAcess(searchName);
                    
                    if ( numOfCopies < quantity){
                        std:: cout << "There are not enough copies in stock.\n\n";
                        break;
                    }else{
                        inv->restockConsole(searchName, quantity);
                    }
                    
                }
                std::cout << "Sold " << quantity << " " << condition << " " << title << "(s).\n\n";
                break;
                
            case 3:
                std::cout<<"\nRemove Preorder\nWhat is the name of the game you preordered?";
                std:: cin >> title;
                searchName = title + "new";
                inv->checkGameStock(searchName);
                if( inv->checkGameStock(searchName) == "Item Not Found" ){
                    std::cout << "Game is either is not in preorder state or not in inventory\n\n";
                    break;
                }
                std::cout<<"\nWhat is the ID number associated with the preorder?\n";
                std:: cin >> IDnumber;
                std:: cout << inv->removePreOrder(searchName, IDnumber) << "\n";
                break;
                
            case 4:
                std::cout<<"\nRestock Item\nIs the item being restocked a (Use letter associated with the choice): \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
                std::cin >> itemType;
                if(itemType != "a" && itemType != "b" && itemType != "c"){
                    std::cout << "Invalid input.";
                    break;
                }
                std::cout << "Enter the name of the item you would like to add: ";
                std::cin >> title;
                std::cout << "New or used? ";
                std::cin >> condition;
                if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                    std::cout << "Invalid input.";
                    break;
                }
                std::cout << "How many would you like to add? ";
                std::cin >> quantity;
                if(quantity < 0){
                    std::cout << "Invalid input.";
                    break;
                }
                //if the item is a game
                if(itemType == "a"){
                    searchName = title + condition;
                    inv->restockGame(searchName, quantity);
                }
                //if the item is a console
                if(itemType == "b"){
                    std::cout << "Enter the edition of the console (If standard edition, press Enter): ";
                    std::cin >> edition;
                    searchName = title + edition + condition;
                    inv->restockConsole(searchName, quantity);
                }
                //if the item is an accessory
                if(itemType == "c"){
                    std::cout << "Enter the name of the console that this accessory is compatible with: ";
                    std::cin >> consoleTo;
                    searchName = title + consoleTo + condition;
                    inv->restockConsole(searchName, quantity);
                }
                std::cout << "Restocked " << quantity << " " << condition << " " << title << "(s).\n\n";
                break;
                
            case 5:
                std::cout<<"\nCheck In Stock Item\nThe type of item you want to check is a (Use letter associated with the choice): \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
                std::cin >> itemType;
                if(itemType != "a" && itemType != "b" && itemType != "c"){
                    std::cout << "Invalid input.";
                    break;
                }
                std::cout<<"Display a list Contain all Items? Y/N [Yes will only return title and condition of each] \n";
                std::cin>>userInputS;
                if(userInputS != "y" && userInputS != "Y" && userInputS != "n" && userInputS != "N"){
                    std::cout << "Invalid input.";
                    break;
                }
                if(userInputS == "y" || userInputS == "Y" ){
                    if(itemType == "a"){
                        std::cout<<inv->getListofGame();
                    }else if(itemType == "b"){
                        std::cout<<inv->getListofConsole();
                    }else{
                        std::cout<<inv->getListofAccess();
                    }
                    break;
                }
                //if the item is a game
                if(itemType == "a"){
                    std::cout << "Enter the name of the item you would like to check (without spaces): ";
                    std::cin >> title;
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    searchName = title + condition;
                    std::cout <<inv->checkGameStock(searchName);
                }
                //if the item is a console
                if(itemType == "b"){
                    std::cout << "Enter the name of the item you would like to check (without spaces): ";
                    std::cin >> title;
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    std::cout << "Enter the edition of the console (If standard edition, press Enter): ";
                    std::cin >> edition;
                    searchName = title + edition + condition;
                    std::cout <<inv->checkConsoleStock(searchName);
                }
                //if the item is an accessory
                if(itemType == "c"){
                    std::cout << "Enter the name of the item you would like to check (without spaces): ";
                    std::cin >> title;
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    std::cout << "Enter the name of the console that this accessory is compatible with: ";
                    std::cin >> consoleTo;
                    searchName = title + consoleTo + condition;
                    std::cout <<inv->checkAcessStock(searchName);
                }
                break;
                
            case 6:
                std::cout<<"\nModify In Stock Item\nWhat type of item do you want ot modify? (Use letter associated with the choice)\n\ta) Game\n\tb) Console\n\tc) Accessory\n";
                std::cin >> itemType;
                if(itemType != "a" && itemType != "b" && itemType != "c"){
                    std::cout << "Invalid input.";
                    break;
                }
                //if the item is a game
                if(itemType == "a"){
                    std::cout<<"\nWhat is the title of the game? (without spaces)";
                    std::cin >> title;
                    
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    searchName = title + condition;
                    if( inv->checkGameStock(searchName) == "Item Not Found" ){
                        std::cout << "Item Not Found";
                        break;
                    }
                    else{
                        std::cout<<"\nWhat would you like to change?\n\t a)Price \n\t b)Make A Preorder Game Avaiable\n";
                        std::cin >> userInputS;
                        
                        if (userInputS == "a") {
                            std::cout<<"\nWhat would you like the new price to be?\n";
                            std::cin >> price;
                            
                            inv->setPriceGame(searchName, price);
                        }
                        if (userInputS == "b") {
                            if ( inv->getPreorderStatus(searchName) ) {
                                inv->comeToStock(searchName);
                            }else{
                                std:: cout << "This game is already on the shelves.";
                            }
                            
                        }
                    }
                }
                
                //if the item is a console
                if(itemType == "b"){
                    std::cout<<"\nWhat is the title of the console? (without spaces)";
                    std::cin >> title;
                    
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    searchName = title + condition;
                    if( inv->checkGameStock(searchName) == "Item Not Found" ){
                        std::cout << "Item Not Found";
                        break;
                    }
                    else{
                        std::cout<<"\nWhat would you like the new price to be?\n";
                        std::cin >> price;
                        
                        inv->setPriceConsole(searchName, price);
                    }
                }
                
                //if the item is an accessory
                if(itemType == "c"){
                    std::cout<<"\nWhat is the title of the accessory? (without spaces)";
                    std::cin >> title;
                    
                    std::cout << "New or used? ";
                    std::cin >> condition;
                    if(condition != "New" && condition != "new" && condition != "Used" && condition != "used"){
                        std::cout << "Invalid input.";
                        break;
                    }
                    searchName = title + condition;
                    if( inv->checkGameStock(searchName) == "Item Not Found" ){
                        std::cout << "Item Not Found";
                        break;
                    }
                    else{
                        std::cout<<"\nWhat would you like the new price to be?\n";
                        std::cin >> price;
                        
                        inv->setPriceAcess(searchName, price);
                        
                    }
                }
                break;
                
            case 7:
                std:: cout << "Here is a Ddiagram of the functionality inside GameStore Inventory Manage System\n";
                
                helpInfo =
                "1) Add New Item\n"
                "\t Allows user to add a new item to the store from that information\n"
                "2) Sell Item\n"
                "\t Allows user to sells a copy or copies from the inventory\n"
                "\t If item is not in stock or does not have enough copies, it will notify user\n"
                "\t If game is in preorder state, it will notify user and allow costumer to preorder game\n"
                "3) Restock Item\n"
                "\t Allows user to adds a copy or copies from the inventory\n"
                "4) Check In Stock Item\n"
                "\t Allows user to print out information about an item or items from the inventory\n"
                "5) Modify In Stock Item Data\n"
                "\t Allows user to change the price of an item and to make a game available"
                "6) Helper\n"
                "\t prints out a diagram of the abilies of the program"
                "7) Shut Down and Save Data\n"
                "\t saves the data about the inventory and exits the program \n";
                
                std:: cout << helpInfo;
                break;
                
            case 8:
                std::cout<<"Saving Data\n";
                inv->toFile("game.txt");
                inv->toFile("console.txt");
                inv->toFile("accessory.txt");
                std::cout<<"Shut Down\n";
                shutdown = true;
                break;
                
            default:
                std:: cout << "\nNumber not recognized. Please try again.";
                break;
                
        }
    }
    delete inv;
}