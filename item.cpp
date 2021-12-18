#include <iostream>
#include "item.h"

using namespace std;

/* Author: Fiona Wang
 * Date: Dec. 17, 2021
 * This is the cpp file for the items in zuul
 */

//Creating and setting item variables
item::item(char* na){
  iname = new char[80];
  strcpy(iname, na);
}

//Returns the name of the item
char* item::getItemName(){
  return iname;
}
