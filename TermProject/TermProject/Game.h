//
//  Game.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Game__
#define __TermProject__Game__

#include <stdio.h>
#include <iostream>
#include "ItemADT.h"
#include "QueueADT.h"

// defined(__TermProject__Game__)
class Game : public ItemADT{

private:
    int numInStock;
    float price;
    std:: string title;
    std:: string genre;
    std:: string rating;
    bool preOrder;
    QueueADT* waitingList;
    std:: string publisher;
    bool preOwned;
    
public:
    //Constructor
    Game(int stockIn, float priceIn, std::string titleIn, std::string genreIn, int ratingIn, bool preOwnedIn, std::string publisherIn);
    
    //Copy constuctor
    Game(Game* gameToCopy);
    
    //creates a string with all of the contents for the game
    std::string toString();
    
    //allows the game to go from preOrder to in stock
    void comeToStock();
    
    //allows a user to preorder the game
    void preOrderGame(std:: string name);
    
    //allows a user to cancle their preorder
    std::string removePreOrder(int idNumber);
    
    //Destructor
    ~Game();
    
};

#endif