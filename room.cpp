#include <iostream>
#include "room.h"
#include "item.h"
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

/* Author: Fiona Wang
 * Date: Dec. 17, 2021
 * This is the cpp file for the zuul room functions
 */

//Creating and setting room variabls
room::room(int d, char* n, map<char, int> e, vector<item*> i){
  name = new char[80];
  strcpy(name, n);
  id=d;
  exits=e;
  copy(i.begin(), i.end(), back_inserter(items));
}

//Getting the room's id
int room::getID(){
  return id;
}

//Prints the name, exits, and items in a room
void room::printDescription(){
  cout << "You are in the " << name << endl;
  cout << "Exits:" << endl;
  map<char, int>::iterator itr;
  for(itr=exits.begin(); itr!=exits.end(); ++itr){
    if(itr->first=='N'){
      cout << "NORTH" << endl;
    } else if(itr->first=='E'){
      cout << "EAST" << endl;
    } else if(itr->first=='S'){
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

//Removes items from a room
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

//Adds items to a room
void room::addItems(char* newIt){
  item* newI = new item(newIt);
  items.push_back(newI);
}

//Searching for a specific exit
bool room::exitExist(char look, char check[]){
  map<char, int>::iterator itr;
  for(itr=exits.begin(); itr!=exits.end(); ++itr){
    if((strcmp(check, "NORTH")==false || strcmp(check, "EAST")==false
	|| strcmp(check, "SOUTH")==false || strcmp(check, "WEST")==false) && look==itr->first){
      return true;
    }
  }
  return false;
}

//Find the room corresponding to the exit
int room::findExit(char look){
  map<char, int>::iterator itr;
  for(itr=exits.begin(); itr!=exits.end(); ++itr){
    if(look==itr->first){
      return itr->second;
    }
  }
  return 0;
}

//Check if an item exists
bool room::findItem(char* look){
  vector<item*>::iterator itr;
  for(int i=0; i<items.size(); i++){
    if(strcmp(look, items[i]->getItemName())==false){
      return true;
    }
  }
  return false;
}
