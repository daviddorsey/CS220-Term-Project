//
//  UI.cpp
//  TermProject
//
//  Created by Danny Kustin on 12/10/15.
//  Copyright (c) 2015 David Dorsey. All rights reserved.
//

#include <stdio.h>
#include <iostream>

//Input: responce from user
//Output: formated repsonce
//Purpose: simply comparisons between user input and computer checks
std:: string formatResponce(std:: string responceIn){
    std::locale loc;
    for(int i = 0; i < responceIn.length(); i++){
        if(responceIn[i] != ' '){
            responceIn[i] = std::tolower(responceIn[i], loc);
        }
        
    }
    responceIn.erase(std::remove(responceIn.begin(), responceIn.end(), ' '), responceIn.end());
    return responceIn;
}

int main(int argc, const char * argv[]) {
    //Driver Variables
    bool shutdown = false;
    std:: string prompt;
    std:: string responce;
    
    //Text filler
    std:: string titlePromt = "What is the title of the ";
    
    //Opening Dialogue
    std:: cout << "Welcome to the GameStore Computer Interface" << std:: endl;
    std:: cout << "Do you want to load data from a previous day? (\"Yes\" / \"No\")" << std:: endl;
    std:: cin >> responce;
    responce = formatResponce(responce);
    
    //Data Trap to ensure use types in good Data
    while (responce != "yes" || responce != "no" ) {
        std:: cout << "Responce not recognized.  Check Input." << std:: endl;
        std:: cout << "Do you want to load data from a previous day? ( \"Yes\" / \"No\" )" << std:: endl;
    }
    
    if (responce == "yes") {
        //Load from file
        std:: cout << "File loaded" << std:: endl;
    }
    
    //Loop to keep program going while game store staff uses it
    while ( !shutdown ){
        
        //Begining Dialogue
        prompt = "What would you like to do? (Number or Text Accoicated With Choice Acceptable ) \n"
                            "\t 1) Sell Item \n"
                            "\t 2) Buy Item Not In Stock \n"
                            "\t 3) Preorder Game \n"
                            "\t 4) Check Stock \n"
                            "\t 5) Make Game Available \n"
                            "\t 6) Change Existng Item Data \n"
                            "\t 7) Shut Down and Save Data \n";
        
        std:: cout << prompt;
        
        std:: cin >> responce;
        responce = formatResponce(responce);
        
        //Data Trap to ensure use types in good Data
        while (responce != "1" || responce != "2" || responce != "3" || responce != "4" || responce != "5" || responce != "6" ||
               responce != "sellitem" || responce != "buyitemnotinstock" || responce != "preordergame" || responce != "checkstock" ||
               responce != "makegameavailable" || responce != "changeexistingitemdata" || responce != "shutdownandsavedata") {
            std:: cout << "Responce not recognized. Check Input." << std:: endl;
            std:: cout << prompt;
        }
        
        //Sell Item
        if (responce == "1" || responce == "sellitem") {
            std:: cout << titlePromt << "item you would like to sell?" << std:: endl;
            std:: cin >> responce;
            //search for title, make false if can not find
            if (false) {
                std:: cout << "Could not find \"" << responce << "\". Check Input or use Buy Item Not In Stock." << std:: endl;
            }
            else{
                std:: cout << "How many copies of \"" << responce << "\" would you like to sell?" << std:: endl;
                std:: cin >> responce;
                try {
                    std::stoi (responce);
                } catch (std::exception) {
                    std:: cout << "Number not inputted" << std:: endl;
                }
            }
            responce = "-1";
        }
        
        //Buy Item Not In Stock
        if (responce == "2" || responce == "buyitemnotinstock") {
            std:: cout << titlePromt << "item you want to add to the stock?" << std:: endl;
            std:: cin >> responce;
            //search for title, make false if find
            if (false) {
                std:: cout << "Found \"" << title << "\". Check Input or use Change Existng Item Data." << std:: endl;
            }
            else{
                
            }
            responce = "-1";
        }
        
        //Preorder Game
        if (responce == "3" || responce == "preordergame") {
            std:: cout << titlePromt << "game you would like to preorder?" << std:: endl;
            std:: cin >> responce;
            
            responce = "-1";
        }
        
        //Check Stock
        if (responce == "4" || responce == "checkstock") {
            std:: cout << titlePromt << "item you would like to check the stock of?" << std:: endl;
            std:: cin >> responce;
            
            responce = "-1";
        }
        
        //Make Game Available
        if (responce == "5" || responce == "makegameavailable") {
            std:: cout << titlePromt << "game you would like to make available?" << std:: endl;
            std:: cin >> responce;
            
            responce = "-1";
        }
        
        //Change Existng Item Data
        if (responce == "6" || responce == "changeexistingitemdata") {
            std:: cout << titlePromt << "item you would like to change the data of?" << std:: endl;
            std:: cin >> responce;
            
            responce = "-1";
        }
        
        //Shut Down and Save Data
        if (responce == "7" || responce == "shutdownandsavedata") {
            //writes to a file
            shutdown = true;
        }
        
    }
    
    return 0;
}