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

#endif /* defined(__TermProject__Game__) */
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
    std:: string toString();
    void comeToStock();
    void preOrderGame(std:: string name);
    void removePreOrder(std:: string name);
};