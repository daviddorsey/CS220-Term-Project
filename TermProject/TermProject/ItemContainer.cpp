//
//  ItemContainer.cpp
//  TermProject
//
//  Created by Jimmy Wang on 12/9/15.
//  Copyright © 2015 David Dorsey. All rights reserved.
//

#include <stdio.h>
#include "ItemContainer.h"

ItemContainer::ItemContainer(){
    size = 10;
    fillIndex= 0;
    inPoint =0;
    dict = new ItemADT*[size];
};

ItemContainer::ItemContainer(const ItemContainer& ItemContainerToCopy){
    size = ItemContainerToCopy.size;
    fillIndex = ItemContainerToCopy.fillIndex;
    dict = new ItemADT*[size];
};

void ItemContainer::add(ItemADT* itemToAdd){
    if(contains(itemToAdd->getSearchName())){
        std::cout<<"Item Not Added, already in."<<std::endl;//
    }else if (fillIndex==size-1){
        doubleSize();
        shiftOrderRight(itemToAdd);
        dict[inPoint] = itemToAdd;
        fillIndex++;
    }else{
        shiftOrderRight(itemToAdd);
        dict[inPoint] = itemToAdd;
        fillIndex++;
    }
};

void ItemContainer::remove(std::string searchName){
    if(!contains(searchName)){
        std::cout<<"Item Not Found"<<std::endl;
    }else{
        if(inPoint == fillIndex-1){
            delete dict[inPoint];
            dict[inPoint]=nullptr;
            fillIndex--;
        }else{
            delete dict[inPoint];
            dict[inPoint]=nullptr;
            shiftOrderLeft();
            fillIndex--;
        }
        
    }
};

void ItemContainer::shiftOrderRight(ItemADT* itemToAdd){
    int tempIndex = fillIndex-1;
    search(itemToAdd->getSearchName());
    int t = fillIndex-inPoint;
    if(t>1){
        for(int i=0; i<t; i++){
            dict[fillIndex-i]=dict[tempIndex-i];
        }
    }
}

void ItemContainer::shiftOrderLeft(){
    int tempIndex = inPoint+1;
    int t = (fillIndex-1)-inPoint;
    for(int i=0; i<t; i++){
        dict[inPoint+i]=dict[tempIndex+i];
    }
    dict[inPoint+t]=nullptr;
}

void ItemContainer::doubleSize(){
    ItemADT** newD = new ItemADT*[size*2];
    for(int i=0;i<fillIndex;i++){
        newD[i]=dict[i];
    }
    size = size*2;
    delete[] dict;
    dict = newD;
    newD = nullptr;
};

ItemADT* ItemContainer::get(std::string searchName){
    if(search(searchName)){
        return dict[inPoint];
    }else{
        return nullptr;
    }
};

bool ItemContainer::contains(std::string searchName){
    if(search(searchName)){
        return true;
    }else{
        return false;
    }
};

bool ItemContainer::search(std::string searchName){
    //    if(size<100){
    return linSearch(searchName);
    //    }else{
    //        return binSearch(searchName);
    //    }
};

bool ItemContainer::linSearch(std::string searchName){
    for(int i=0; i<fillIndex;i++){
        if(dict[i]!=nullptr){
            if(dict[i]->getSearchName()==searchName){
                inPoint =i;
                return true;
            }
            if(dict[i]->getSearchName()>searchName){
                inPoint =i;
                break;
            }else{
                inPoint = fillIndex;
            }
        }
    }
    return false;
}

bool ItemContainer::binSearch(std::string searchName){
    int low = 0, high = fillIndex, midpoint = 0;
    while (low <= high && high>0){
        midpoint = low + (high - low)/2;
        if (searchName== dict[midpoint]->getSearchName()){
            return true;
        }else if(searchName< dict[midpoint]->getSearchName()){
            high = midpoint - 1;
        }else{
            low = midpoint + 1;
        }
    }
    inPoint = high+1;
    return false;
}

//Destructor
ItemContainer::~ItemContainer(){
    for (int i = 0; i < size; i++){
        delete dict[i];
    }
    delete[] dict;
    dict=nullptr;
};