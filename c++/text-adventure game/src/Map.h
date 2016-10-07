#pragma once

#include <vector>
#include "Room.h"
#include "EntityFactory.h"
#include "EntityPlayer.h"


/// \brief Map Class
///
class Map
{
  public:
   /// \brief Constructs the map of the game. 
   ///
   /// \param[in] difficulty, the difficulty of the game.  
   /// \param[inout] &player, a reference to the player.
   Map(int diff, EntityPlayer *p);

   /// \brief Deconstructs the map of the game.
   ~Map();
   
   /// \brief Generates map of the rooms
   ///
   /// \return bool : returns true if map is generated correctly.
   bool generate();
   
   /// \brief Moves player to given room in map
   ///
   /// \param[in] the pointer to the room you want to move the player to
   void movePlayer(Room *room);
   
   /// \brief Displays description of the room
   ///
   /// \returns Bool: returns true if description succesfully prints.
   bool displayDescription();
   
   /// \brief gets the hieght of the room in the map tree.
   ///
   /// /param[in] &room, a reference to the room that the height is need for.
   /// /return const int: returns the hieght of the room in the map tree.
   Room* getCurRoom()const{return curRoom;};

   void getRandomRoom(Room *&c);


   int getX() {return curRoom->getX();};
   int getY() {return curRoom->getY();};
   std::vector<int> getOpVec(){return curRoom->setOptions();};
   Room* getMap(int x, int y){return map[x][y];};
   std::vector<std::vector<Room*> > getFullMap(){return map;};
  private:
   int startX = 0;
   int startY = 0;
   int difficulty = 1;
   int sizeX = 5;
   int sizeY = 5;
   std::vector<std::vector<Room*> > map;
   Room *curRoom;
   EntityPlayer *player;
   int currentX=0;
   int currentY=0;
};
