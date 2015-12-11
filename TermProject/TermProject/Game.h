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
#include "Item.h"
#include "QueueADT.h"

// defined(__TermProject__Game__)
class Game : public Item{

private:
    int numInStock;
    float price;
    std:: string title;
    std:: string genre;
    std:: string rating;
    bool preorder;
    QueueADT* waitingList;
    std:: string publisher;
    bool preowned;
    std:: string searchName;
    std::string searchFormat(std::string s);
    
public:
    //Constructor
    Game(int stockIn, float priceIn, std::string titleIn, std::string genreIn, std::string ratingIn, bool preOwnedIn, std::string publisherIn);
    
    //Copy constuctor
    Game(Game* gameToCopy);
    
    //creates a string with all of the contents for the game
    std::string toString();
    
    //creates a string with all of the contents for the game reordered for file writing
    std::string fileFormat();
    
    //allows the game to go from preOrder to in stock
    void comeToStock();
    
    //allows a user to preorder the game
    int preOrderGame(std:: string name);
    
    //allows a user to cancle their preorder
    std::string removePreOrder(int idNumber);
    
    //Getters
    std:: string getGenre();
    std:: string getRating();
    std:: string getPublisher();
    std:: string getSearchName();
    
    //Setters
    void setGenre(std::string genreIn);
    void setRating(std::string ratingIn);
    void setPublisher(std::string publisherIn);
    
    //Destructor
    ~Game();
    
};

#endif