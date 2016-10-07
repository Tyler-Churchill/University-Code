#pragma once

#include <string>
#include "Attributes.h"
#include "Item.h"

/// \brief Weapon Class to be generated by the ItemFactory
class Weapon : public Item
{
  public:

   /// \brief Equips the weapon
   ///
   /// /return bool if the item was used
   bool use();
   
  private:
   std::string name;
   std::string description;
   Attributes stats;
};
