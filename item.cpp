#include <iostream>
#include "item.h"

using namespace std;

item::item(char* na){
  iname = new char[80];
  strcpy(iname, na);
}

char* item::getItemName(){
  return iname;
}
