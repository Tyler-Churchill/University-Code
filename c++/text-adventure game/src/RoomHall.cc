#include "RoomHall.h"
#include "EntityFactory.h"

void RoomHall::generate()
{
   setEntity(EntityFactory::getInstance()->getEnemy(BAT,this)); 
}


std::string RoomHall::getDescription()
{
   std::string description = "You enter a long hallway with torches casting a luminous glow. \n";
   if (getNorth()!=nullptr)
   {
      description+="There is a door at the  North end of the hall.";
      description+="\n";
   }
   if (getSouth()!=nullptr)
   {
      description+="There is a door at the south end of the hall.";
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

bool RoomHall::isEmpty()
{
   return false;
}
