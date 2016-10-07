#include "RoomStandard.h"
#include "EntityFactory.h"

void RoomStandard::generate()
{
   
   setEntity(EntityFactory::getInstance()->getEnemy(SPIDER,this)); 
}


std::string RoomStandard::getDescription()
{
   std::string description = "You enter a room with art covering the walls.  \n";
      if (getNorth()!=nullptr)
      {
	 description+="There is door to the north of you ";
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
	 description+="There is a door to the West.";
	 description+="\n";
      }
   return description;
}

bool RoomStandard::isEmpty()
{
   return false;
}
