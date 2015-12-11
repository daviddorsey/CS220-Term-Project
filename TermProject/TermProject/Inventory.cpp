//
//  Inventory.cpp
//  TermProject
//
//  Created by Jimmy Wang on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>


Inventory::Inventory(){
    numGames = 0;
    numConsoles = 0;
    numAccessories = 0;
};

Inventory::Inventory(const Inventory &inventoryToCopy){
    
};
//turn user input string to searchName
std::string Inventory::toSearchFormat(std::string s){
    std::locale loc;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            s[i] = std::tolower(s[i], loc);
        }
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

//Add new item
void Inventory::addAcessStock(Accessory* itemToAdd){
    acessStock.add(itemToAdd);
    numAccessories++;
};
void Inventory::addGameStock(Game* itemToAdd){
    gameStock.add(itemToAdd);
    numGames++;
};
void Inventory::addConsoleStock(Console* itemToAdd){
    consoleStock.add(itemToAdd);
    numConsoles++;
    
};

std::string Inventory::checkAcessStock(std::string title){
    ItemADT* temp = acessStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        return temp->toString();
    }else{
        return "Item Not Found";
    }
    
};
std::string Inventory::checkGameStock(std::string title){
    ItemADT* temp = gameStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        return temp->toString();
    }else{
        return "Item Not Found";
    }
    
};
std::string Inventory::checkConsoleStock(std::string title){
    ItemADT* temp = consoleStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        return temp->toString();
    }else{
        return "Item Not Found";
    }
};

std::string  Inventory::restockAcess(std::string title, int numCopies){
    ItemADT* temp = acessStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->buy(numCopies);
        return "Item Restocked";
    }else{
        return "Item Not Found";
    }
};

std::string  Inventory::restockGame(std::string title, int numCopies){
    ItemADT* temp = gameStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->buy(numCopies);
        return "Item Restocked";
    }else{
        return "Item Not Found";
    }
};
std::string  Inventory::restockConsole(std::string title, int numCopies){
    ItemADT* temp = consoleStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->buy(numCopies);
        return "Item Restocked";
    }else{
        return "Item Not Found";
    }
};


std::string  Inventory::sellAcess(std::string title, int sellAmount){
    ItemADT* temp = acessStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->sell(sellAmount);
        return "Item Sold";
    }else{
        return "Item Not Found";
    }
};
std::string  Inventory::sellGame(std::string title, int sellAmount){
    ItemADT* temp = gameStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->sell(sellAmount);
        return "Item Sold";
    }else{
        return "Item Not Found";
    }
};
std::string  Inventory::sellConsole(std::string title, int sellAmount){
    ItemADT* temp = consoleStock.get(toSearchFormat(title));
    if(temp!=nullptr){
        temp->sell(sellAmount);
        return "Item Sold";
    }else{
        return "Item Not Found";
    }
};


void Inventory::removeAcess(std::string title){
    acessStock.remove(toSearchFormat(title));
    numAccessories--;
};
void Inventory::removeGame(std::string title){
    gameStock.remove(toSearchFormat(title));
    numGames--;
};
void Inventory::removeConsole(std::string title){
    consoleStock.remove(toSearchFormat(title));
    numConsoles--;
};

//helper function for reading from file and casting string to bool
bool to_bool(std::string s){
    return s != "0";
}

void Inventory::fromFile(std::string filename){
    
    std::ifstream infile(filename);
    if (infile){
        if(filename == "game.txt"){
            while (infile){
                if(infile){
                    std::string strInput;
                    std::getline(infile, strInput);
                    if(strInput.length()>0){
                        std::stringstream splitter(strInput);
                        std::string title,price,copies,condition,genre,rating,maker;
                        getline(splitter,title,',');
                        getline(splitter,price,',');
                        getline(splitter,copies,',');
                        getline(splitter,condition,',');
                        getline(splitter,genre,',');
                        getline(splitter,rating,',');
                        getline(splitter,maker,',');
                        Game* g = new Game(stoi(copies), stof(price), title, genre,rating, to_bool(condition),maker);
                        gameStock.add(g);
                        std::cout << "\nRead:\t" << g->toString() << "\n";

                    }
                }
                
            }
        }
        if(filename == "console.txt"){
            while (infile){
                if(infile){
                    std::string strInput;
                    std::getline(infile, strInput);
                    if(strInput.length()>0){
                        std::stringstream splitter(strInput);
                        std::string title,price,copies,condition,edition,maker,warranty;
                        getline(splitter,title,',');
                        getline(splitter,price,',');
                        getline(splitter,copies,',');
                        getline(splitter,condition,',');
                        getline(splitter,edition,',');
                        getline(splitter,maker,',');
                        getline(splitter,warranty,',');
                        Console* c = new Console(stoi(copies), stof(price), title, edition,maker, stoi(warranty), to_bool(condition));
                        gameStock.add(c);
                        std::cout << "\nRead:\t" << c->toString() << "\n";
                        
                    }
                }
                
            }
        }
        if(filename == "accessory.txt"){
            while (infile){
                if(infile){
                    std::string strInput;
                    std::getline(infile, strInput);
                    if(strInput.length()>0){
                        std::stringstream splitter(strInput);
                        std::string title,price,copies,condition,consoleTo,warranty;
                        getline(splitter,title,',');
                        getline(splitter,price,',');
                        getline(splitter,copies,',');
                        getline(splitter,condition,',');
                        getline(splitter,consoleTo,',');
                        getline(splitter,warranty,',');
                        Accessory* a = new Accessory(stoi(copies), stof(price), title, consoleTo, to_bool(condition), stoi(warranty));
                        gameStock.add(a);
                        std::cout << "\nRead:\t" << a->toString() << "\n";
                        
                    }
                }
                
            }
        }
    }
    else {
        std::cout << "Can't read from file. Inventory not loaded.\n";
    }
}


void Inventory::toFile(std::string filename){

    std::ofstream outf(filename);
    if (outf){
        
        if(filename == "game.txt"){
            for(int i = 0; i < numGames; i++){
                ItemADT* curr = gameStock.get(i);
                if(curr != nullptr){
                    outf << curr->fileFormat() + ",\n";
                }
            }
        }
        
        if(filename == "console.txt"){
            for(int i = 0; i < numConsoles; i++){
                ItemADT* curr = consoleStock.get(i);
                if(curr != nullptr){
                    outf << curr->fileFormat() + ",\n";
                }
            }

        }
        
        if(filename == "accessory.txt"){
            for(int i = 0; i < numAccessories; i++){
                ItemADT* curr = acessStock.get(i);
                if(curr != nullptr){
                    outf << curr->fileFormat() + ",\n";
                }
            }
        }
        
        outf.close();
    }
    else { // Print an error and exit
        std::cout << "Unable to write to file.\n";
    }
}
