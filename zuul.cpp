#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include "room.h"
#include "item.h"

using namespace std;

void go(vector<room*> &rooms);
void get(vector<room*> &rooms);
void drop(vector<room*> &rooms);

int main(){
  vector<room*> rooms;
  vector<char*> inventory;
  char GO[] = "GO";
  char GET[] = "GET";
  char HELP[] = "HELP";
  char DROP[] = "DROP";
  char INVENTORY[] = "INVENTORY";
  char QUIT[] = "QUIT";
  char input[80];
  bool play=true;

  map<char, int> closetE;
  closetE['e']=1;
  closetE['s']=4;
  vector<item*> closetI;
  char* closetN = new char[7];
  strcpy(closetN, "closet"); 
  room* closet = new room(0, closetN, closetE, closetI);
  rooms.push_back(closet);
  char* mopN= new char[4];
  strcpy(mopN, "MOP");
  rooms[0]->addItems(mopN);
  
  cout << "Welcome to Sunset High School!" << endl;
  cout << "Someone spilled their lunch and need your help to bring the mop from the closet to the cafeteria" << endl;
  rooms[0]->printDescription();
  //print cafeteria information

  while(play==true){
    char firstword[20];
    char secondword[20];
    cin.get(input, 80);
    cin.get();

    for(int i=0; i < strlen(input); i++) {
      input[i] = toupper(input[i]);
    }

    int i=0;
    for(i=0; i < strlen(input); i++) {
      firstword[i]=input[i];
      if(input[i+1]==' ' || input[i+1]=='\0'){
	break;
      }
    }
    firstword[i+1]='\0';

    int x=0;
    int y=0;
    for(x=i+2; x<strlen(input); x++) {
      secondword[y]=input[x];
      y++;
      if(input[x+1]=='\0'){break;}
    }
    secondword[x+1]='\0';
    
    if(strcmp(firstword, GO)==false) {
      go(rooms);
    } else if(strcmp(firstword,GET)==false){
      get(rooms);
    } else if(strcmp(firstword, HELP)==false){
      cout << "Enter 'go' to go through an exit, 'get' to pick up an item, 'drop' to drop an item, 'inventory' to check what items you have, and 'quit' to end the game" << endl;
    } else if(strcmp(firstword, DROP)==false){
      drop(rooms);
    } else if(strcmp(firstword, INVENTORY)==false){
      cout << "print items" << endl;
    } else if(strcmp(firstword, QUIT)==false){
      return 0;
    } else{
      cout << "Please enter a valid command" << endl;
    }
  }
}

void go(vector<room*> &rooms){
  cout << "go function" << endl;
  //find the exit the user inputed
  //print out the new room info
}

void get(vector<room*> &rooms){
  cout << "get function" << endl;
  //find the item
  //remove the item from the room
  //add to inventory
}

void drop(vector<room*> &rooms){
  cout << "drop function" << endl;
  //find item in inventory
  //remove item form inventory
  //put item in room
}
