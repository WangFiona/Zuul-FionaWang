#ifndef	ROOM_H
#define	ROOM_H
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include "item.h"

using namespace std;

/* Author: Fiona Wang
 * Date: Dec. 17, 2021
 * This is the header file for the rooms in zuul.
 */

class room{
 public:
  room(int d, char* n, map<char,int> e, vector<item*> i);

  //Initialize variables
  int id;
  map<char, int> exits;
  vector<item*> items;
  char* name;

  //Declare functions
  virtual int getID();
  virtual void printDescription();
  virtual void removeItems(char it[]);
  virtual void addItems(char* newIt);
  virtual bool exitExist(char look, char check[]);
  virtual int findExit(char look);
  virtual bool findItem(char* look);
};
#endif
