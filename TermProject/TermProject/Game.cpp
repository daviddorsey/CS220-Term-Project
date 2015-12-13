#include "Console.h"
#include "Game.h"
#include "Queue.h"

//helper function for formatting search name
std::string Game::searchFormat(std::string s){
    std::locale loc;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            s[i] = std::tolower(s[i], loc);
        }
        
    }
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
    return s;
};

//Constructor
Game:: Game(int stockIn, float priceIn, std::string titleIn, std::string genreIn, std::string ratingIn, bool preownedIn, std::string publisherIn, bool preorderIn){
    numInStock = stockIn;
    price = priceIn;
    title = titleIn;
    genre = genreIn;
    rating = ratingIn;
    preowned = preownedIn;
    preorder = preorderIn;
    publisher = publisherIn;
    waitingList = new Queue();
    searchName = searchFormat(title)+"new";
    if(preowned)
        searchName = searchFormat(title)+"used";
};

//Copy Constructor
Game:: Game(Game* gameToCopy){
    
    numInStock = gameToCopy->numInStock;
    price = gameToCopy->price;
    title = gameToCopy->title;
    genre = gameToCopy->genre;
    rating = gameToCopy->rating;
    preowned = gameToCopy->preowned;
    publisher = gameToCopy->publisher;
    for (int i = 0; i < gameToCopy->waitingList->sizeOf(); i++) {
        gameToCopy->waitingList->get(i);
    }
};

//Destructor
Game:: ~Game(){
    
    delete waitingList;
    
}
bool Game::getPreorderStatus(){
    return preorder;
};
int Game::getNumInStock(){
    return numInStock;
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
    result += "Genre: " + genre + "\n";
    
    if (preowned) {
        result += "Condition: Preowned \n";
    }
    else{
        result += "Condition: New \n";
    }
    
    if(preorder){
        result += "This game can only be preordered at this time \n";
        result += "The waiting list for this game is: \n";
        result += waitingList->toString();
        
    }
    else{
        result += "This game can be purchased now \n";
        
    }
    
    return result;
}

std::string Game::fileFormat(){
    return title + "," + std::to_string(price) + "," + std::to_string(numInStock) + "," + std::to_string(preowned) + "," + genre + "," + rating + "," + publisher;
}

//Input: Nothing
//Output: Nothing
//Purpose: to switch a game from being preOwned to abled to be purchased
void Game:: comeToStock(){
    
    if (!preorder) {
        std:: cout << "This game is already on the shelves \n";
    }
    
    if(waitingList->isEmpty()){
        preorder = false;
        return;
    }
    
    else{
        
        for (int i = 0; i < waitingList->sizeOf(); i++) {
            std:: cout << waitingList->get(i) <<"recieved " << title <<",";
        }
        delete waitingList;
        waitingList = nullptr;
        preorder = false;
        
    }
    
}


//Input: name of person to add to waiting list
//Output:
//Purpose: to allow a user to preorder agame
int Game:: preOrder(std:: string name){
    
    if (!preorder) {
        std:: cout << "This game is already on the shelves \n";
        std:: cout << "You can purchase it if you like \n";
    }
    else{
        return waitingList->enqueue(name);
    }
    return -1;
}

std::string Game:: removePreOrder(int idNumber){
    return waitingList->dequeue(idNumber);
   
}

void Game::sell(int amount){
    if(amount<=numInStock){
        numInStock -= amount;
    }
};

//Getters:
std::string Game:: getTitle(){
    return title;
}
std:: string Game:: getGenre(){
    return genre;
}
std:: string Game:: getRating(){
    return rating;
}
std:: string Game:: getPublisher(){
    return publisher;
}
std::string Game:: getSearchName(){
    return searchName;
}


//Setters:
void Game:: setGenre(std:: string genreIn){
    genre = genreIn;
}
void Game:: setRating(std::string ratingIn){
    rating = ratingIn;
}
void Game:: setPublisher(std::string publisherIn){
    publisher = publisherIn;
}

