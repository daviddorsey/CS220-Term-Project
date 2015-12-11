//
//#include <stdio.h>
//#include <iostream>
//
////Input: responce from user
////Output: formated repsonce
////Purpose: simply comparisons between user input and computer checks
//std:: string formatResponce(std:: string responceIn){
//    std::locale loc;
//    for(int i = 0; i < responceIn.length(); i++){
//        if(responceIn[i] != ' '){
//            responceIn[i] = std::tolower(responceIn[i], loc);
//        }
//        
//    }
//    responceIn.erase(std::remove(responceIn.begin(), responceIn.end(), ' '), responceIn.end());
//    return responceIn;
//}
//
//int main(int argc, const char * argv[]) {
//    //Driver Variables
//    bool shutdown = false;
//    std:: string prompt;
//    std:: string responce;
//    bool inInventory;
//    
//    //Text filler
//    std:: string titlePromt = "What is the title of the ";
//    
//    //Opening Dialogue
//    std:: cout << "Welcome to the GameStore Computer Interface" << std:: endl;
//    std:: cout << "Do you want to load data from a previous day? (\"Yes\" / \"No\")" << std:: endl;
//    std:: cin >> responce;
//    responce = formatResponce(responce);
//    
//    //Data Trap to ensure use types in good Data
//    while (responce != "yes" || responce != "no" ) {
//        std:: cout << "ERROR: Responce not recognized.  Check input." << std:: endl;
//        std:: cout << "Do you want to load data from a previous day? ( \"Yes\" / \"No\" )" << std:: endl;
//    }
//    
//    if (responce == "yes") {
//        //Load from file
//        std:: cout << "File loaded" << std:: endl;
//    }
//    
//    //Loop to keep program going while game store staff uses it
//    while ( !shutdown ){
//        
//        //Begining Dialogue
//        prompt = "What would you like to do? ( Number or Text Accoicated With Choice Acceptable ) \n"
//                            "\t 1) Sell Item \n"
//                            "\t 2) Buy Item Not In Stock \n"
//                            "\t 3) Preorder Game \n"
//                            "\t 4) Remove Preorder \n"
//                            "\t 5) Check Stock \n"
//                            "\t 6) Make Game Available \n"
//                            "\t 8) Change Existng Item Data \n"
//                            "\t 8) Shut Down and Save Data \n";
//        
//        std:: cout << prompt;
//        
//        std:: cin >> responce;
//        responce = formatResponce(responce);
//        
//        //Data Trap to ensure use types in good Data
//        while (responce != "1" || responce != "2" || responce != "3" || responce != "4" || responce != "5" || responce != "6" || responce != "7" ||
//               responce != "sellitem" || responce != "buyitemnotinstock" || responce != "preordergame" || responce != "removepreorder" ||
//               responce != "checkstock" || responce != "makegameavailable" || responce != "changeexistingitemdata" ||
//               responce != "shutdownandsavedata") {
//            std:: cout << "ERROR: Responce not recognized. Check input." << std:: endl;
//            std:: cout << prompt;
//        }
//        
//        //Sell Item
//        if (responce == "1" || responce == "sellitem") {
//            std:: cout << titlePromt << "item you would like to sell?" << std:: endl;
//            std:: cin >> responce;
//            //search for title
//            if ( !inInventory ) {
//                std:: cout << "ERROR: Could not find \"" << responce << "\". Check input or use \"Buy Item Not In Stock\"." << std:: endl;
//            }
//            
//            else{
//                if (/*Preorder*/) {
//                    std:: cout << "ERROR:  \"" << responce << "\" is not avaible yet. It can be preordered in \"Preorder Game\"." << std:: endl;
//                }
//                
//                else{
//                    std:: cout << "How many copies of \"" << responce << "\" would you like to sell?" << std:: endl;
//                    std:: cin >> responce;
//                    try {
//                        std::stoi (responce);
//                    } catch (std::exception) {
//                        std:: cout << "ERROR: Number not inputted" << std:: endl;
//                    }
//                    //sell item
//                }
//            }
//            
//            responce = "-1";
//        }
//        
//        //Buy Item Not In Stock
//        if (responce == "2" || responce == "buyitemnotinstock") {
//            std:: cout << titlePromt << "item you want to add to the stock?" << std:: endl;
//            std:: cin >> responce;
//            //search for title
//            if ( inInventory ) {
//                std:: cout << "ERROR: Found \"" << responce << "\". Check input or use \"Change Existng Item Data\"." << std:: endl;
//            }
//            
//            else{
//                std:: cout << "How many copies of \"" << responce << "\" would you like to sell?" << std:: endl;
//                std:: cin >> responce;
//                try {
//                    std::stoi (responce);
//                } catch (std::exception) {
//                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                }
//                //buy item
//            }
//            
//            responce = "-1";
//        }
//        
//        //Preorder Game
//        if (responce == "3" || responce == "preordergame") {
//            std:: cout << titlePromt << "game the customer would like to preorder?" << std:: endl;
//            std:: cin >> responce;
//            //search for title
//            if ( !inInventory ) {
//                std:: cout << "ERROR: Could not find \"" << responce << "\". Check input or use \"Buy Item Not In Stock\"." << std:: endl;
//            }
//            else{
//                if (/*!Preorder*/) {
//                    std:: cout << "ERROR: \"" << responce << "\" is out right now. It can be sold in \"Sell Item\"." << std:: endl;
//                }
//                
//                else{
//                    std:: cout << "What is the number of the customer that wants to preoder the game?" << std:: endl;
//                    std:: cin >> responce;
//                    int idNum;
//                    //preodergame
//                    std:: cout << "Preorder Created. The costumer has the ID number of " << std::to_string( idNum ) <<"." << std:: endl;
//                    std:: cout<< "He/she will need it if he/she decides to revoke his/ her preorder" <<  std:: endl;
//                }
//                
//            }
//            
//            responce = "-1";
//        }
//        
//        //Remove Preorder
//        if (responce == "4" || responce == "removepreorder") {
//            std:: cout << "What is the ID number associated with the customer?" << std:: endl;
//            std:: cin >> responce;
//            std:: string removePreorderResponce;
//            //removePreoder;
//            if( removePreorderResponce == "No one with that ID Number found"){
//                std:: cout << "ERROR: " << removePreorderResponce;
//            }
//            
//            else{
//                std:: cout << removePreorderResponce << " was removed.";
//            }
//            
//            responce = "-1";
//        }
//        
//        //Check Stock
//        if (responce == "5" || responce == "checkstock") {
//            std:: cout << titlePromt << "item you want to check the stock of?" << std:: endl;
//            std:: cin >> responce;
//            //search for title
//            if ( !inInventory ) {
//                std:: cout << "ERROR: Could not find \"" << responce << "\". Check input." << std:: endl;
//            }
//            
//            else{
//                //getStockNum
//                int stockNum;
//                std:: cout << "There are " << std:: to_string( stockNum ) << " copies of \"" << responce << "\" in the inventory." << std:: endl;
//            }
//            
//            responce = "-1";
//        }
//        
//        //Make Game Available
//        if (responce == "6" || responce == "makegameavailable") {
//            std:: cout << titlePromt << "game you would like to make available?" << std:: endl;
//            std:: cin >> responce;
//            if (/*!Preorder*/) {
//                std:: cout << "ERROR: \"" << responce << "\" is out right now. It can be sold in \"Sell Item\"." << std:: endl;
//            }
//            
//            else{
//                //make available
//            }
//            
//            responce = "-1";
//        }
//        
//        //Change Existng Item Data
//        if (responce == "7" || responce == "changeexistingitemdata") {
//            std:: cout << "What type is the item you would like to change the data for? ( Number or Text Accoicated With Choice Acceptable )" << std:: endl;
//            std:: cout << "\t 1) Game" << std:: endl;
//            std:: cout << "\t 2) Console" << std:: endl;
//            std:: cout << "\t 3) Accessory" << std:: endl;
//            std:: cin >> responce;
//            if (responce == "1" || responce == "2" || responce == "3" || responce == "game" || responce == "console" || responce == "accessory") {
//                if (responce == "1" || responce == "game") {
//                    std:: cout << titlePromt << "game you would like to change the data of?" << std:: endl;
//                    std:: cin >> responce;
//                    //search for title in games
//                    if ( !inInventory ) {
//                        std:: cout << "ERROR: Could not find \"" << responce << "\". Check input or try a different type of item." << std:: endl;
//                    }
//                    
//                    else{
//                        std:: cout << "What would you like to change in \"" << responce << "\"? ( Number or Text Accoicated With Choice Acceptable )" << std:: endl;
//                        std:: cout << "1) Add To Stock" << std:: endl;
//                        std:: cout << "2) Change Price" << std:: endl;
//                        std:: cin >> responce;
//                        if (responce != "1" || responce != "2" || responce != "addtostock" || responce != "changeprice") {
//                            std:: cout << "ERROR: Responce not recognized.  Check input.";
//                        }
//                        
//                        else{
//                            
//                            if (responce == "1" || responce == "addtostock") {
//                                std:: cout << "How many copies do you want to buy?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stoi (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //get stock
//                                //stock += add
//                            }
//                            if (responce == "2" || responce == "changeprice") {
//                                std:: cout << "What would you like the new price to be?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stof (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //set price
//                            }
//                            
//                        }
//                    }
//                }
//                if (responce == "2" || responce == "console") {
//                    std:: cout << titlePromt << "console you would like to change the data of? ( Number or Text Accoicated With Choice Acceptable )" << std:: endl;
//                    std:: cin >> responce;
//                    //search for title in console
//                    if ( !inInventory ) {
//                        std:: cout << "ERROR: Could not find \"" << responce << "\". Check input or try a different type of item." << std:: endl;
//                    }
//                    
//                    else{
//                        std:: cout << "What would you like to change in \"" << responce << "\"? ( Number or Text Accoicated With Choice Acceptable )" << std:: endl;
//                        std:: cout << "1) Add To Stock" << std:: endl;
//                        std:: cout << "2) Change Price" << std:: endl;
//                        std:: cin >> responce;
//                        if (responce != "1" || responce != "2" || responce != "addtostock" || responce != "changeprice") {
//                            std:: cout << "ERROR: Responce not recognized.  Check input.";
//                        }
//                        
//                        else{
//                            
//                            if (responce == "1" || responce == "addtostock") {
//                                std:: cout << "How many copies do you want to buy?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stoi (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //get stock
//                                //stock += add
//                            }
//                            if (responce == "2" || responce == "changeprice") {
//                                std:: cout << "What would you like the new price to be?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stof (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //set price
//                            }
//                            
//                        }
//                    }
//                }
//                if (responce == "3" || responce == "accessory") {
//                    std:: cout << titlePromt << "accessory you would like to change the data of?" << std:: endl;
//                    std:: cin >> responce;
//                    //search for title in accessory
//                    if ( !inInventory ) {
//                        std:: cout << "ERROR: Could not find \"" << responce << "\". Check input or try a different type of item." << std:: endl;
//                    }
//                    
//                    else{
//                        std:: cout << "What would you like to change in \"" << responce << "\"? ( Number or Text Accoicated With Choice Acceptable )" << std:: endl;
//                        std:: cout << "1) Add To Stock" << std:: endl;
//                        std:: cout << "2) Change Price" << std:: endl;
//                        std:: cin >> responce;
//                        if (responce != "1" || responce != "2" || responce != "addtostock" || responce != "changeprice") {
//                            std:: cout << "ERROR: Responce not recognized.  Check input.";
//                        }
//                        
//                        else{
//                            
//                            if (responce == "1" || responce == "addtostock") {
//                                std:: cout << "How many copies do you want to buy?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stoi (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //get stock
//                                //stock += add
//                            }
//                            if (responce == "2" || responce == "changeprice") {
//                                std:: cout << "What would you like the new price to be?" << std:: endl;
//                                std:: cin >> responce;
//                                try {
//                                    std::stof (responce);
//                                } catch (std::exception) {
//                                    std:: cout << "ERROR: Number not inputted" << std:: endl;
//                                }
//                                //set price
//                            }
//                            
//                        }
//                    }
//                }
//                
//            }
//            
//            responce = "-1";
//        }
//        
//        //Shut Down and Save Data
//        if (responce == "8" || responce == "shutdownandsavedata") {
//            //writes to a file
//            shutdown = true;
//        }
//        
//    }
//    
//    return 0;
//}
