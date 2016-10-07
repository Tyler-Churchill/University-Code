#pragma once

#include "Entity.h"
#include <iostream>

/// \brief EntitySkeleton
///
class EntitySkeleton : public Entity
{
  public:
   
   /// \brief Function that will call an attack on the Skeleton provided
   ///
   /// \param[in] Entity &entity
   bool attack(Entity &entity);
   
   /// \brief Function that checks to see if the Skeleton is alive or not, a boolean value does so
   /// \return boolean to see if alive(true) or dead(false)
   bool isAlive();

   /// \brief Function that updates the Skeleton's next decision
   ///
   void update();

   /// \brief Function that gives loot to the selected Skeleton
   ///
   /// \param[in] Entity &entity
   void getLoot(Entity &entity);

   /// \brief Function that checks to see if the Entity has loot and returns a boolean value to do so
   /// \return boolean to see if has loot(true) or not(false)
   bool hasLoot(); 
};
