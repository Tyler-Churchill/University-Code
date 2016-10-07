#pragma once

#include <string>
#include "Entity.h"
#include "Item.h"
#include "Room.h"
//#include "Player.h"

///
/// \brief Entity class
///
class EntityPlayer : public Entity
{
  public:
   /// \brief constructor for player
   ///
   /// constructs the player
   EntityPlayer();

   /// \brief destructor for player
   ///
   /// destructs the player pointer
   ~EntityPlayer();

      
      /// \brief Attacks the given entity
   ///
   /// Detailed description
   /// \param[in] entity, a reference to the entity that will be attacked
   bool attack(Entity &entity);

   
   /// \brief Returns true if the entity is alive, false if dead
   ///
   /// Detailed description
   /// \return Returns true if the entity is alive, false if dead
   bool isAlive();



   /// \brief Gives the loot from the entity to the given entity (transfers inventory to the referenced entity)
   ///
   /// Detailed description
   /// \param[in] entity, the entity you want to get its inventory from
   void getLoot(Entity &entity);

   /// \brief Returns true if the entity has items in their inventory, false otherwise
   ///
   /// Detailed description
   /// \return boolean returns if the entity has loot or not
   bool hasLoot();

   /// \brief Updates the player's stats based on their new item
   ///
   /// Detailed description
   /// \param none
  

   /// \brief equips item to available spot
   ///
   /// Changes the equipped weapon slot then forces updates to player's stats
   /// \param none
   void equipArmor(Item *item);
   
   /// \brief equips item to available spot
   ///
   /// Changes the equipped armor slot then forces update to player's stats
   void equipWeapon(Item *item);

   /// \brief uses potion
   ///
   /// Uses the potion and gets rid of it
   void usePotion(Item *item, int x);

   
  private:
   Item *equippedWeapon;
   Item *equippedArmor;
   Item* q;
   Item* j;
};
