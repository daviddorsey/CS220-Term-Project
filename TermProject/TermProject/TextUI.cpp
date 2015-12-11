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
    bool shutdown = false;
    std:: string prompt;
    std:: string userInput;
    
    
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
        
    }
}