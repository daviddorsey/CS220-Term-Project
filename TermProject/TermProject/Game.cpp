/Constructor
Game:: Game(){
    
}

//Copy Constructor
Game:: Game(Game gameToCopy){
    
}

//Destructor
Game:: ~Game(){
    
}

//Input: Nothing
//Output: Formated String of all Game information
//Purpose: To get all the information about the Game
std:: string Game:: toString(){
    std:: string result = "Title: " + title + "\n";
    result += "Price " + std::to_string(price) + "\n";
    result += std::to_string(numInStock) + " copies in stock \n";
    result += "Rating " + rating + "\n";
    result += "Made by: " + publisher + "\n";
    
    if (preOwned) {
        result += "Condition: Preowned \n";
    }
    else{
        result += "Condition: New \n";
    }
    
    if(preOrder){
        result += "This game can only be preordered at this time \n";
        result += "The waiting list for this game is: \n";
        
        for (int i = 0; i < waitingList->sizeOf(); i++) {
            <#statements#>
        }
        
    }
    else{
        result += "This game can be purchased now \n";
        
    }
    
    return result;
}

//Input: Nothing
//Output: Nothing
//Purpose: to switch a game from being preOwned to abled to be purchased
void Game:: comeToStock(){
    
    if (!preOrder) {
        std:: cout << "This game is already on the shelves \n";
    }
    
    if(waitingList->isEmpty()){
        preOrder = false;
        return;
    }
    
    else{
        
        for (int i = 0; i < waitingList->sizeOf(); i++) {
            std:: cout << <<"recieved " << title <<",";
        }
        delete waitingList;
        waitingList = nullptr;
        preOrder = false;
        
    }
    
}

void Game:: preOrderGame(std:: string name){
    
    if (!preOrder) {
        std:: cout << "This game is already on the shelves \n";
        std:: cout << "You can purchase it if you like \n";
    }
    
    else{
        waitingList->enqueue(name);
    }
    
}

void Game:: removePreOrder(std:: string name){
    
    for (int i = 0; i < waitingList->sizeOf(); i++) {
        waitingList->dequeue();
    }
    
}