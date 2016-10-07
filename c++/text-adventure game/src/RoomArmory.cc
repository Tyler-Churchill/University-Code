#include "RoomArmory.h"
#include "EntityFactory.h"



void RoomArmory::generate()
{
   setEntity(EntityFactory::getInstance()->getEnemy(TROLL,this)); 
}


std::string RoomArmory::getDescription()
{
   std::string description = "You enter an armory with weapons lining the walls. \n";
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

bool RoomArmory::isEmpty()
{
   return false;
}
