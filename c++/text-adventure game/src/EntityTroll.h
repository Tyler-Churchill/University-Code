#pragma once

#include "Entity.h"

/// \brief class EntityTroll
///
class EntityTroll : public Entity
{
  public:

   
   /// \brief Function that calls an attack on the given Troll
   ///
   /// \param[in] EntityTroll &entity
   bool attack(Entity &entity);
   
   /// \brief Function that checks to see if the Entity is alive and returns a boolean value to determine such
   ///
   /// \return boolean if alive(true) or dead(false)
   bool isAlive();

   /// \brief Function that updates the Entity's next decision
   ///
  

   /// \brief Function that gives loot to the currently selected Troll
   ///
   /// \param[in] EntityTroll &entity
   void getLoot(Entity &entity);

   /// \brief Function that checks to see if the Entity has loot and returns a boolean value to do so
   ///
   /// \return boolean if has loot(true) or not(false)
   bool hasLoot(); 
};
