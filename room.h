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

class room{
 public:
  //room();
  room(int d, char* n, map<char,int> e, vector<item*> i);

  int id;
  map<char, int> exits;
  vector<item*> items;
  char* name;
  virtual int getID();
  virtual void printDescription();
  virtual void setExits();
  virtual void removeItems(char it[]);
  virtual void addItems(char* newIt);
  virtual int findExit(char look);
  virtual bool findItem(char* look);
};
#endif
