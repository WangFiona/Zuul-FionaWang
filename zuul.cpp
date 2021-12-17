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
  int id=4;

  //Office information
  map<char, int> officeE;
  officeE['E']=1;
  officeE['S']=4;
  vector<item*> officeI;
  char* officeN = new char[10];
  strcpy(officeN, "office");
  room* office = new room(0, officeN, officeE, officeI);
  rooms.push_back(office);
  char* paperN= new char[10];
  strcpy(paperN, "PAPER");
  rooms[0]->addItems(paperN);
  
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
  map<char, int> counselorsE;
  counselorsE['W']=2;
  counselorsE['S']=7;
  vector<item*> counselorsI;
  char* counselorsN = new char[30];
  strcpy(counselorsN, "counselor's office");
  room* counselor = new room(3, counselorsN, counselorsE, counselorsI);
  rooms.push_back(counselor);
  
  //Cafeteria information
  map<char, int> cafeE;
  cafeE['E']=5;
  cafeE['S']=8;
  cafeE['N']=0;
  vector<item*> cafeI;
  char* cafeN = new char[20];
  strcpy(cafeN, "cafeteria");
  room* cafe = new room(4, cafeN, cafeE, cafeI);
  rooms.push_back(cafe);
  
  //Gym information
  map<char, int> gymE;
  gymE['N']=1;
  gymE['E']=6;
  gymE['S']=9;
  gymE['W']=4;
  vector<item*> gymI;
  char* gymN = new char[20];
  strcpy(gymN, "gym");
  room* gym = new room(5, gymN, gymE, gymI);
  rooms.push_back(gym);

  //1-20 information
  map<char, int> oneE;
  oneE['N']=2;
  oneE['E']=7;
  oneE['S']=10;
  oneE['W']=5;
  vector<item*> oneI;
  char* oneN = new char[20];
  strcpy(oneN, "computer lab");
  room* one = new room(6, oneN, oneE, oneI);
  rooms.push_back(one);
  char* robotN= new char[10];
  strcpy(robotN, "ROBOT");
  rooms[6]->addItems(robotN);
  
  //Lecture Hall information
  map<char, int> lectureE;
  lectureE['N']=3;
  lectureE['S']=11;
  lectureE['W']=6;
  vector<item*> lectureI;
  char* lectureN = new char[20];
  strcpy(lectureN, "lecture hall");
  room* lecture = new room(7, lectureN, lectureE, lectureI);
  rooms.push_back(lecture);
  char* pencilsN= new char[10];
  strcpy(pencilsN, "PENCILS");
  rooms[7]->addItems(pencilsN);
  
  //Kitchen information
  map<char, int> kitchenE;
  kitchenE['E']=9;
  kitchenE['S']=12;
  kitchenE['N']=4;
  vector<item*> kitchenI;
  char* kitchenN = new char[20];
  strcpy(kitchenN, "kitchen");
  room* kitchen = new room(8, kitchenN, kitchenE, kitchenI);
  rooms.push_back(kitchen);
  
  //Pub information
  map<char, int> pubE;
  pubE['N']=5;
  pubE['E']=10;
  pubE['S']=13;
  pubE['W']=8;
  vector<item*> pubI;
  char* pubN = new char[20];
  strcpy(pubN, "pub");
  room* pub = new room(9, pubN, pubE, pubI);
  rooms.push_back(pub);
  
  //Garden information
  map<char, int> gardenE;
  gardenE['N']=6;
  gardenE['E']=11;
  gardenE['S']=14;
  gardenE['W']=9;
  vector<item*> gardenI;
  char* gardenN = new char[20];
  strcpy(gardenN, "garden");
  room* garden = new room(10, gardenN, gardenE, gardenI);
  rooms.push_back(garden);
  
  //Theatre information
  map<char, int> theatreE;
  theatreE['N']=7;
  theatreE['S']=15;
  theatreE['W']=10;
  vector<item*> theatreI;
  char* theatreN = new char[20];
  strcpy(theatreN, "theatre");
  room* theatre = new room(11, theatreN, theatreE, theatreI);
  rooms.push_back(theatre);

  //Library information
  map<char, int> libraryE;
  libraryE['E']=13;
  libraryE['N']=8;
  vector<item*> libraryI;
  char* libraryN = new char[10];
  strcpy(libraryN, "library");
  room* library = new room(12, libraryN, libraryE, libraryI);
  rooms.push_back(library);
  char* computerN= new char[10];
  strcpy(computerN, "COMPUTER");
  rooms[12]->addItems(computerN);
  
  //Art room information
  map<char, int> artE;
  artE['E']=14;
  artE['N']=9;
  artE['W']=12;
  vector<item*> artI;
  char* artN = new char[13];
  strcpy(artN, "art room");
  room* art = new room(13, artN, artE, artI);
  rooms.push_back(art);
  
  //Lab information
  map<char, int> labE;
  labE['E']=15;
  labE['N']=10;
  labE['W']=13;
  vector<item*> labI;
  char* labN = new char[13];
  strcpy(labN, "lab");
  room* lab = new room(13, labN, labE, labI);
  rooms.push_back(lab);

  //Closet information
  map<char, int> closetE;
  closetE['W']=14;
  closetE['N']=11;
  vector<item*> closetI;
  char* closetN = new char[7];
  strcpy(closetN, "closet");
  room* closet = new room(15, closetN, closetE, closetI);
  rooms.push_back(closet);
  char* mopN= new char[4];
  strcpy(mopN, "MOP");
  rooms[15]->addItems(mopN);
  
  cout << "Welcome to Zuul University!" << endl;
  cout << "Someone spilled their lunch and need your help to bring the mop from the closet to the cafeteria" << endl;
  cout << "Enter 'help' to see the commands" << endl;
  
  rooms[4]->printDescription();

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
      cout << "The commands:" << endl;
      cout << "Enter 'go [one of the exits]' to go through an exit" << endl;
      cout << "Enter 'get [name of the item]' to pick an item up" << endl;
      cout << "Enter 'drop [name of the item]' to drop an item" << endl;
      cout << "Enter 'inventory' to check what items you have" << endl;
      cout << "Enter 'quit' to end the game" << endl;
      //cout << "Enter 'go' to go through an exit, 'get' to pick up an item, 'drop' to drop an item, 'inventory' to check what items you have, and 'quit' to end the game" << endl;
    } else if(strcmp(firstword, DROP)==false){
      drop(id, rooms, secondword, inventory);
      if(rooms[4]->findItem(mopN)==true){
	cout << "You brought the mop to the cafeteria. You win!" << endl;
	play=false;
      }
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
  for(i=inventory.begin(); i!=inventory.end(); ++i){
    if(strcmp(look, inventory[x])==false){
      rooms[id]->addItems(look);
      cout << *i << endl;
      inventory.erase(i);
      cout << look << " has been dropped and removed from your inventory" << endl;
      return;
    }
    x++;
  }
  cout << look << " is not in your inventory" << endl;
}
