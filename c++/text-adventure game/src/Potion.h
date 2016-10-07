#pragma once

#include <string>
#include "Attributes.h"
#include "Item.h"

/// \brief Weapon Class to be generated by the ItemFactory
class Potion : public Item
{
  public:

   /// \brief Equips the potion
   ///
   /// Detailed description
   /// /return bool if the potion was sucessfully used
   bool use();

  private:
   std::string name;
   std::string description;
   Attributes stats;
};
