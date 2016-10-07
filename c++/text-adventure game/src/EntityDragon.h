#pragma once

#include "Entity.h"

/// \brief class EntityDragon
///
class EntityDragon : public Entity
{
  public:
   /// \brief Constructor for the Dragon that puts a Dragon into the world
   ///
   EntityDragon();
   
   /// \brief Function that calls an attack on the currently selected Dragon
   ///
   /// \param[in] EntityDragon &entity
   void attack(Entity &entity);
   
   /// \brief Function that checks to see if the Entity is alive and returns a boolean
   /// value that does such
   ///
   /// \param[in] none
   /// \return boolean to check if alive(true) or dead(false)
   bool isAlive();

   /// \brief Function that updates the Entity's next decision UNUSED
   ///
   void update();

   /// \brief Function that gives loot to the currently selected Dragon
   ///
   /// \param[in] EntityDragon &entity
   void getLoot(Entity &entity);

   /// \brief Function that checks to see if the Entity has loot and returns a boolean
   /// value to determine such
   ///
   /// \return boolean if yes(true) or no(false)
   bool hasLoot(); 
};
