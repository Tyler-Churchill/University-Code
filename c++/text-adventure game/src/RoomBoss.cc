#include "RoomBoss.h"
#include "EntityFactory.h"
void RoomBoss::generate()
{
    setEntity(EntityFactory::getInstance()->getEnemy(DRAGON,this)); 
}


std::string RoomBoss::getDescription()
{
   std::string description = "Mechachang is staring you straight in the face. \n";
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

      description+=" : There is a door to your East.";
      description+="\n";
   }
   if (getWest()!=nullptr)
   {

      description+=" : There is a door to your West.";
      description+="\n";
   }   
   return description;
}

bool RoomBoss::isEmpty()
{
   return false;
}
