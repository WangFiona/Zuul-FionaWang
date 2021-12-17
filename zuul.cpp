#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include "room.h"
#include "item.h"

using namespace std;

void go(int &id, vector<room*> &rooms, char secondword[]);
void get(int id, vector<room*> &rooms, char secondword[], vector<char*> &inventory);
void drop(int id, vector<room*> &rooms, char secondword[], vector<char*> &inventory);

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
  int id=0;

  //Closet information
  map<char, int> closetE;
  closetE['E']=1;
  closetE['S']=4;
  vector<item*> closetI;
  char* closetN = new char[7];
  strcpy(closetN, "closet"); 
  room* closet = new room(0, closetN, closetE, closetI);
  rooms.push_back(closet);
  char* mopN= new char[4];
  strcpy(mopN, "MOP");
  rooms[0]->addItems(mopN);

  //Parking lot information
  map<char, int> parkingE;
  parkingE['E']=2;
  parkingE['S']=5;
  parkingE['W']=0;
  vector<item*> parkingI;
  char* parkingN = new char[13];
  strcpy(parkingN, "parking lot");
  room* parking = new room(1, parkingN, parkingE, parkingI);
  rooms.push_back(parking);

  //Band room information
  map<char, int> bandE;
  bandE['E']=3;
  bandE['S']=6;
  bandE['W']=1;
  vector<item*> bandI;
  char* bandN = new char[20];
  strcpy(bandN, "band room");
  room* band = new room(2, bandN, bandE, bandI);
  rooms.push_back(band);
  char* fluteN= new char[10];
  strcpy(fluteN, "FLUTE");
  rooms[2]->addItems(fluteN);
  char* violinN= new char[10];
  strcpy(violinN, "VIOLIN");
  rooms[2]->addItems(violinN);
  
  //Counselors room information
  //Cafeteria information
  //Gym information
  //1-20 information
  //Lecture Hall information
  //Kitchen information
  //Pub information
  //Garden information
  //Theatre information
  //Library information
  //Art room information
  //Lab information
  //Office information
  
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
    secondword[y]='\0';
    
    if(strcmp(firstword, GO)==false) {
      go(id, rooms, secondword);
    } else if(strcmp(firstword,GET)==false){
      get(id, rooms, secondword, inventory);
    } else if(strcmp(firstword, HELP)==false){
      cout << "Enter 'go' to go through an exit, 'get' to pick up an item, 'drop' to drop an item, 'inventory' to check what items you have, and 'quit' to end the game" << endl;
    } else if(strcmp(firstword, DROP)==false){
      drop(id, rooms, secondword, inventory);
    } else if(strcmp(firstword, INVENTORY)==false){
      if(inventory.empty()==false){
        cout << "In your inventory:" << endl;
        for(int i=0; i<inventory.size(); i++){
  	  cout << inventory[i] << endl;
        }
      } else{
	cout << "Your inventory is empty" << endl;
      }
    } else if(strcmp(firstword, QUIT)==false){
      return 0;
    } else{
      cout << "Please enter a valid command" << endl;
    }
  }
}

void go(int &id, vector<room*> &rooms, char secondword[]){
  char look=secondword[0];
  if(rooms[id]->exitExist(look)==true){
    id=rooms[id]->findExit(look);
    rooms[id]->printDescription();
  }else{
    cout << "That exit does not exist" << endl;
  }
}

void get(int id, vector<room*> &rooms, char secondword[], vector<char*> &inventory){
  char* look = new char[10];
  strcpy(look, secondword);
  if(rooms[id]->findItem(look)==true){
    rooms[id]->removeItems(secondword);
    inventory.push_back(look);
    cout << look << " has been added to your inventory" << endl;
  } else{
    cout << "This item does not exist" << endl;
  }
}

void drop(int id, vector<room*> &rooms, char secondword[], vector<char*> &inventory){
  char* look = new char[10];
  strcpy(look, secondword);
  vector<char*>::iterator i;
  int x=0;
  for(i=inventory.begin(); i<inventory.end();){
    if(strcmp(look, inventory[x])==false){
      rooms[id]->addItems(look);
      inventory.erase(i);
      cout << look << " has been dropped and removed from your inventory" << endl;
      return;
    }
    x++;
  }
  cout << look << " is not in your inventory" << endl;
}
