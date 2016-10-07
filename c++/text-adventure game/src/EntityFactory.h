#pragma once

#include "Entity.h"
#include "Room.h"
#include <vector>
#include <time.h> 


///
/// \brief EntityFactory class
///
class Room;
class EntityFactory
{

   
   static EntityFactory* __instance;
   
  public:
   /// \brief Grabs the current single instance of EntityFactory
   ///
   /// \return EntityFactory, the current instance of the entity factory
   static EntityFactory* getInstance();
   /// \brief Returns a generated enemy entity
   ///
   /// \param[in] Entity enum you want to make
   /// \param[in] Room where entity is made, This is used to scale the entity as the dungeon progresses
   /// \return Returns the generated enemy
   Entity* getEnemy(ENTITYTYPE e, Room *x);
 /// \brief Returns an inventory containing a random item, uses room as a seed
   ///
   /// \param[in] Room to make the item in, this is used to scale the item
   /// 
   /// \return Returns an inventory containing a random item
   std::vector<Item*> makeInventory(Room *x);


};
