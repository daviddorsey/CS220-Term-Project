//
//  TextUI.cpp
//  TermProject
//
//  Created by Jimmy Wang on 12/11/15.
//  Copyright © 2015 David Dorsey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Inventory.h"
#include "ItemADT.h"

void TextUI(){
    Inventory* inv = new Inventory();
    bool shutdown = false;
    std:: string prompt;
    int userInput;
    
    
    std:: cout << "Welcome to the GameStore Inventory Manage systerm " << std:: endl;
    while ( !shutdown ){
        prompt = "Select to Continue\n"
        "1) Add New Item \n"
        "2) Restock Item \n"
        "3) Check Stock Item \n"
        "4) Modify Existng Item Data \n"
        "5) Shut Down and Save Data \n";
        
        //prints the prompt
        std:: cout << prompt;
        std:: cin >> userInput;
        std::string itemType, title, condition, manufacturer, edition, consoleTo, publisher, rating, genre;
        int quantity, warranty;
        float price;

            switch (userInput) {
                    
            case 1:
                std::cout<<"\nAdd New Item\nIs the new item a: \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
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
                    Game* g;
                    if(condition == "New" || condition == "new")
                        g = new Game(quantity, price, title, genre, rating, false, publisher);
                    else
                        g = new Game(quantity, price, title, genre, rating, true, publisher);
                    inv->addGameStock(g);
                }
                //brings in data members specific to console
                if(itemType == "b"){
                    std::cout << "Enter the edition of the console (If standard edition, press Enter): ";
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
                    if(condition == "New" || condition == "new")
                        c = new Console(quantity, price, title, edition, manufacturer, warranty, false);
                    else
                        c = new Console(quantity, price, title, edition, manufacturer, warranty, true);
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
                std::cout<<"\nRestock Item\nIs the item being restocked a: \n\ta) Game\n\tb) Console\n\tc) Accessory\n";
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
                    std::string searchName = title + condition;
                    inv->restockGame(searchName, quantity);
                }
                //if the item is a console
                if(itemType == "b"){
                    std::cout << "Enter the edition of the console (If standard edition, press Enter): ";
                    std::cin >> edition;
                    std::string searchName = title + edition + condition;
                    inv->restockConsole(searchName, quantity);
                }
                //if the item is an accessory
                if(itemType == "c"){
                    std::cout << "Enter the name of the console that this accessory is compatible with: ";
                    std::cin >> consoleTo;
                    std::string searchName = title + consoleTo + condition;
                    inv->restockConsole(searchName, quantity);
                }
                std::cout << "Restocked " << quantity << " " << condition << " " << title << "(s).\n\n";
                break;
            case 3:
                std::cout<<"Check Stock Item\n";
                break;
            case 4:
                std::cout<<"Modify Existng Item Data\n";
                break;
            case 5:
                std::cout<<"Shut Down and Save Data\n";
                break;
            default:
                break;
        }
        
    }
}