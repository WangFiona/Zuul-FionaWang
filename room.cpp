#include <iostream>
#include "room.h"
#include "item.h"
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

room::room(int d, char* n, map<char, int> e, vector<item*> i){
  name = new char[80];
  strcpy(name, n);
  id=d;
  exits=e;
  copy(i.begin(), i.end(), back_inserter(items));
}

int room::getID(){
  return id;
}

void room::printDescription(){
  cout << "You are in the " << name << endl;
  cout << "Exits:" << endl;
  map<char, int>::iterator itr;
  for(itr=exits.begin(); itr!=exits.end(); ++itr){
    if(itr->first=='n'){
      cout << "NORTH" << endl;
    } else if(itr->first=='e'){
      cout << "EAST" << endl;
    } else if(itr->first=='s'){
      cout << "SOUTH" << endl;
    } else{
      cout << "WEST" << endl;
    }
  }
  
  if(items.size()>0){
    cout << "Items: " << endl;
    for(int i=0; i<items.size(); i++){
      cout << items[i]->getItemName() << endl;
    }
  } else{
    cout << "There are no items in this room" << endl;
  }
}

void room::setExits(){
  
}

void room::removeItems(char it[]){
  vector<item*>::iterator i;
  item* ptr;
  for(i=items.begin(); i<items.end(); i++){
    ptr=*i;
    if(strcmp(it, ptr->getItemName())==false){
      items.erase(i);
    }
  }
}

void room::addItems(char* newIt){
  item* newI = new item(newIt);
  items.push_back(newI);
}

int room::findExit(char look){
  map<char[], char[]>::iterator itr;
  return exits.at(look);
  //return exits.find(look)->second;
  /*for(itr=exits.begin(); itr!=exits.end(); itr++){
    if(look==itr->second){
      return itr->first;
    }
    }*/
  /*char noExit[4]="NA";
  return noExit;*/
}

bool room::findItem(char* look){
  vector<item*>::iterator itr;
  for(int i=0; i<items.size(); i++){
    //for(itr=items.begin(); itr!=items.end(); itr++){
    if(strcmp(look, items[i]->getItemName())==false){
      return true;
    }
  }
  return false;
}
