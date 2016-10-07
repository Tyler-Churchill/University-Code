#include "Map.h"
#include "Room.h"
#include <random>
#include <ctime>
#include "RoomStandard.h"
#include "RoomBoss.h"
#include "RoomJail.h"
#include "RoomHall.h"
#include "RoomArmory.h"
#include <string>


Map::Map(int diff, EntityPlayer *p)
{
   player = p;
   sizeX = diff * 5;
   sizeY = diff * 5;
   difficulty = diff;
   map.assign(sizeX, std::vector<Room*>(sizeY, nullptr));
}

Map::~Map()
{
   
   unsigned X = sizeX;
   unsigned Y = sizeY;
   for(unsigned x = 0; x!=X; x++)
   {
      for(unsigned y = 0; y!=Y; y++)
      {
	 delete[] map[x][y];
      } 
   }
   
}

bool Map::generate()
{
   bool finished = false;
   int curX=0;
   int curY=0;
   int maxConnections = 2 * sizeX;
   int curConnections = 0;
   
   
   map[0][0] = new RoomBoss();
   map[0][0]->setX(0);
   map[0][0]->setY(0);
   map[0][0]->generate(); 
   while(!finished)
   {
      
      
      int r = 1 + (rand() % (int) (100));
      int weight = 0;
      if(r <= 32)
	 weight = 1;
      if(r >= 64 && r < 79)
	 weight = 2;
      if(r >= 79 && r <= 100)
	 weight = 3;
      if(r > 32 && r < 64)
	 weight = 4;
      switch(weight)
      {
	 // try right
	 case 1:
	    if(curX + 1 < sizeX)
	    {
	       if(map[curX + 1][curY] == nullptr)
	       {
		  // CREATE A NEW ROOM TO THE RIGHT OF CURRENT
		  // map[curX + 1][curY] = getRandomRoom();
		  getRandomRoom(map[curX + 1][curY]);
		  map[curX][curY]->setEast(map[curX + 1][curY]);
		  curX++;
		  map[curX][curY]->setX(curX);
		  map[curX][curY]->setY(curY);
		  map[curX][curY]->generate();
		  map[curX][curY]->setWest(map[curX - 1][curY]);
		  curConnections++;
		  
	       }
	       else
	       {
		  if( map[curX][curY]->getEast() == nullptr)
		     curConnections++;
		  map[curX + 1][curY]->setWest(map[curX][curY]);
		  map[curX][curY]->setEast(map[curX + 1][curY]);
		  curX++;	  
	       }
	    }
	    break;
	    
	    //try down
	 case 2:
	    if(curY - 1 >= 0 && !(curX == 0 && curY == 1))
	    {
	       if(map[curX][curY - 1] == nullptr)
	       {
		  // CREATE A NEW ROOM DOWN OF CURRENT
		  //map[curX][curY - 1] = getRandomRoom();
		  getRandomRoom(map[curX][curY - 1]);
		  map[curX][curY]->setSouth(map[curX][curY - 1]);
		  curY--;
		  map[curX][curY]->setX(curX);
		  map[curX][curY]->setY(curY);
		  map[curX][curY]->generate();
		  map[curX][curY]->setNorth(map[curX][curY + 1]);
		  curConnections++;
	       }
	       else
	       {
		  if( map[curX][curY]->getSouth() == nullptr)
		     curConnections++;
		  map[curX][curY - 1]->setNorth(map[curX][curY]);
		  map[curX][curY]->setSouth(map[curX][curY - 1]);
		  curY--;
	       }
	    }
	    break;

	    // try left
	 case 3:
	    if(curX - 1 > 0 && !(curX == 1 && curY == 0))
	    {
	       if(map[curX - 1][curY] == nullptr)
	       {
		  // we know the room to the left is in range and null, not existing.

		  // CREATE A NEW ROOM TO THE LEFT OF CURRENT
		  //map[curX - 1][curY] = getRandomRoom();
		  getRandomRoom(map[curX -1][curY]);
		  map[curX][curY]->setWest(map[curX - 1][curY]);
		  curX--;
		  map[curX][curY]->setX(curX);
		  map[curX][curY]->setY(curY);
		  map[curX][curY]->generate();
		  map[curX][curY]->setEast(map[curX + 1][curY]);
		  curConnections++;
	       }
	       else
	       {
		  if(map[curX][curY]->getWest() == nullptr)
		     curConnections++;
		  map[curX - 1][curY]->setEast(map[curX][curY]);
		  map[curX][curY]->setWest(map[curX - 1][curY]);
		  curX--;  
	       }
	    }

	    break;
	    
	    // try up
	 case 4:
	    if(curY + 1 < sizeY)
	    {
	       if(map[curX][curY + 1] == nullptr)
	       {
		  // we know the room to the left is in range and null, not existing.

		  // CREATE A NEW ROOM UP OF CURRENT
		  // map[curX][curY + 1] = getRandomRoom();
		  getRandomRoom(map[curX][curY + 1]);
		  map[curX][curY]->setNorth(map[curX][curY + 1]);
		  curY++;
		  map[curX][curY]->setX(curX);
		  map[curX][curY]->setY(curY);
		  map[curX][curY]->generate();
		  map[curX][curY]->setSouth(map[curX][curY - 1]);
		  curConnections++;
	       }
	       else
	       {
		  if( map[curX][curY]->getNorth() == nullptr)
		     curConnections++;
		  map[curX][curY + 1]->setSouth(map[curX][curY]);
		  map[curX][curY]->setNorth(map[curX][curY + 1]);
		  curY++;
		  
	       }
	    }
	    break;
      }

      if(curConnections == maxConnections)
      {
	 currentX = curX;
	 currentY = curY;
	 curRoom = map[curX][curY];
	 finished = true;
	 
      }
   }
   return true;
}


void Map::getRandomRoom(Room *&c)
{
   int r = rand() % 100;
//   std::cout<<r<<std::endl;
   if(r>=25)
   {
      c = new RoomStandard();
   }
   else if (r>25 && r<=50)
   {
      c = new RoomJail();
   }
   else if (r>50&&r<=75)
   {
      c = new RoomHall();
   }
   else
   {
      c = new RoomArmory();
   }
}

void Map::movePlayer(Room *room)
{
   curRoom = room;
   currentX=room->getX();
   currentY=room->getY();
}

bool Map::displayDescription()
{
   int option=0;
   std::cout<<curRoom->getDescription()<<std::endl;
   curRoom->setOptions();
   if(curRoom->getOptions(0)==1)
   {
      option++;
      std::cout<<option<<" : Enter the North Door."<<std::endl;
   }
   if(curRoom->getOptions(1)==1)
   {
      option++;
      std::cout<<option<<" : Enter the South Door."<<std::endl;
   }
   if(curRoom->getOptions(2)==1)
   {
      option++;
      std::cout<<option<<" : Enter the East Door."<<std::endl;
   }
   if(curRoom->getOptions(3)==1)
   {
      option++;
      std::cout<<option<<" : Enter the West Door."<<std::endl;
   }
   if(curRoom->getOptions(4)==1)
   {
      option++;
      std::cout<<option<<" : Attack Enemy."<<std::endl;
   }
   if(curRoom->getOptions(5)==1)
   {
      option++;
      std::cout<<option<<" : Open Inventory."<<std::endl;
   }
   if(curRoom->getOptions(6)==1)
   {
      option++;
      std::cout<<option<<" : Quit."<<std::endl;
   }
   
   return true;
}



