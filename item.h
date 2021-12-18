#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <cstring>

using namespace std;

/* Author: Fiona Wang
 * Date: Dec. 17, 2021
 * This is the header file for the items in zuul
 */

class item{
 public:
  item(char* na);

  //Initialize variables and declare the function
  char* iname;
  virtual char* getItemName();
};
#endif
