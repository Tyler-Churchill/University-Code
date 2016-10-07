#pragma once

#include "Entity.h"

/// \brief class EntitySpider
///
class EntitySpider : public Entity
{
  public:
   /// \brief Function that will call an attack on the Spider given
   ///
   /// \param[in] Entity &entity
   bool attack(Entity &entity);
   
   /// \brief Function checks to see if the Spider is currently alive or not and returns a boolean value to determine so
   /// \return boolean to see if alive(true) or dead(false)
   bool isAlive();

   /// \brief Function updates the Spider to make a decision one thing at a time
   ///
   void update();

   /// \brief Function that gives loot to the Spider passed in
   ///
   /// \param[in] Entity &entity
   void getLoot(Entity &entity);

   /// \brief Function checks to see if Spider passed in contains loot
   ///
   /// \return boolean if has loot(true) or not(false)
   bool hasLoot(); 
};
