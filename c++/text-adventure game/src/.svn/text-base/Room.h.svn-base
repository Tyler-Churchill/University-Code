#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Entity.h"
#include "EntityFactory.h" 

///
/// \brief Class Room 
///
class Room
{
  public:

   virtual ~Room()
   {
      if(east != nullptr)
	 east=nullptr;
      if(north != nullptr)
	 north=nullptr;
      if(south != nullptr)
	 south=nullptr;
      if(west != nullptr)
         west=nullptr;
      //delete entity;
      delete this;
   };
   
   /// \brief Generates the room
   ///
   /// This function generates which enemies will appear in the room with player
   /// \param[in] none 
   /// \return void 
   virtual void generate() = 0;
   
   /// \brief Gets the description for the room
   ///
   /// This function tells the user what is in and around the room 
   /// \param[in] none
   /// \return string-that describes the room's condition
   virtual std::string getDescription() = 0;
   
   void setNorth(Room *p) { north = p; }
   void setSouth(Room *p) { south = p; }
   void setEast(Room *p) { east = p; }
   void setWest(Room *p) { west = p; }
   Room* getNorth() { return north; }
   Room* getSouth() { return south; }
   Room* getEast() { return east; }
   Room* getWest() { return west; }
   void setX(int x){ posX=x;}
   void setY(int y){ posY=y; }
   int getX(){ return posX;}
   int getY(){ return posY;}
   
   int getOptions(int x)
   {
      return options.at(x);

   }
   
   std::vector<int> setOptions()
   {
      //north
      if (north!=nullptr)
      {
	 options.at(0)=1;
      }
      //south
      if (south!=nullptr)
      {
	 options.at(1)=1;
      }
      //east
      if (east!=nullptr)
      {
	 options.at(2)=1;
      }
      //west
      if (west!=nullptr)
      {
	 options.at(3)=1;
      }
      
      //ATTACK
      //if the enmemy is alive
      
      if(entity->isAlive())
      {
	 options.at(4)=1;
      }

      if(!(entity->isAlive()))
      {
	 options.at(4)=0;
      }
      
      int total = options.at(0)+options.at(1)+options.at(2)+options.at(3)+options.at(4)+options.at(5)+options.at(6);
      options.at(7)=total;
      return options;
   }


   Room& operator=(const Room& r)
   {
      if(!(*this == r))
      {
	 north = r.north;
	 west = r.west;
	 south = r.south;
	 east = r.east;
	 setX(r.posX);
	 setY(r.posY);
      }
      return *this;
   }

   
  // TO DO: FINISH == CHECK
  bool operator==(const Room &r1)
  {
     if(*this == r1)
	return true;
     return false;
  }
  
  void setVEC(int x,int y){options.at(x)=y;}
  void setEntity(Entity* x){entity  = x;}
  Entity* getEntity(){return entity;};
  private:
   Room *north = nullptr;
   Room *east = nullptr;
   Room *west = nullptr;
   Room *south = nullptr;
   int posX = 0;
   int posY = 0;
   std::string name;
   std::vector<int> options = {0,0,0,0,0,1,1,0};//{north 0,south 1,east 2,west 3,Attack 4,invetory 5, quit 6)
   Entity *entity;
};

