//
//  Console.h
//  TermProject
//
//  Created by David Dorsey on 11/17/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#ifndef __TermProject__Console__
#define __TermProject__Console__

#include <stdio.h>
#include <string>

class Console{
    
private:
    //number of a specific console that the store has in stock
    int numInStock;
    //the price of each console
    float price;
    //name of the console
    std::string title;
    //name of the edition if it is a special edition, otherwise will just be "default"
    std::string edition;
    //name of the company that makes the console
    std::string manufacturer;
    //number of months that a warranty is available for
    int warranty;
    //stores whether the console is new or used
    bool preowned;
    
public:
    //default constructor
    Console();
    //overloaded constructor
    Console(float priceIn, std::string titleIn, std::string editionIn, std::string manufacturerIn, int warrantyIn, bool preownedIn);
    void toString();
    
};

#endif /* defined(__TermProject__Console__) */
