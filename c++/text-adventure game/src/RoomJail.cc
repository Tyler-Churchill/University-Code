#include "RoomJail.h"
#include "EntityFactory.h"
void RoomJail::generate()
{
   setEntity(EntityFactory::getInstance()->getEnemy(SKELETON,this)); 
}


std::string RoomJail::getDescription()
{
   std::string description = "You enter a room with iron bar cells all the way down. \n";
   if (getNorth()!=nullptr)
   {
      description+="There is a door to the North of you.";
      description+="\n";
   }
   if (getSouth()!=nullptr)
   {
      description+="There is a door to the South of you.";
      description+="\n";
   }
   if (getEast()!=nullptr)
   {
      description+="There is a door to your East.";
      description+="\n";
   }
   if (getWest()!=nullptr)
   {
      description+="There is a door to your West.";
      description+="\n";
   }   

   return description;
}


bool RoomJail::isEmpty()
{
   return false;
}
