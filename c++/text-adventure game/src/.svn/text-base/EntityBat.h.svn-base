#pragma once

#include "Entity.h"
#include <iostream>

class EntityBat : public Entity
{
  public:
  
   /// \brief Function that calls an attack on the given Bat
   ///
   /// \param[in] Entity &entity
   bool attack(Entity &entity);
   
   /// \brief Function that checks to see if the Bat is alive, returns a boolean
   /// value to determine such
   ///
   /// \return boolean returns if the bat is alive(true) or dead(false)
   bool isAlive();

   /// \brief Function that updates the Bat to make its next decision *UNUSED*
   /// 
   void update();

   /// \brief Function that gives the loot to the selected Bat
   ///
   /// \param[in] Entity &entity
   void getLoot(Entity &entity);

   /// \brief Function that checks to see if the current Bat has loot or not
   ///
   /// \return boolean if bat has loot yes(true), no(false)
   bool hasLoot(); 
};
