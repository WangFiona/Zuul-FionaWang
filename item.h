#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

class item{
 public:
  item(char* na);

  char* iname;
  virtual char* getItemName();
};
#endif
