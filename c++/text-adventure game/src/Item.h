#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include "Attributes.h"

enum ITEMTYPE {SWORD, ARMOR, HEALTH_POTION};

/// \brief Item Class pure virtual interface for item classes
///     
class Item
{
  public:
   
   /// \brief virtual destructor
   virtual ~Item(){ delete this;};

   /// \brief Gets the name of the item and returns it
   ///
   /// \return string containing the item name 
   std::string getName() { return name;};
   
   /// \brief Gets the description of the item and returns it
   ///
   /// Detailed description
   /// /return string of the items description
   std::string getDescription() {return description;};

   /// \brief Equips the item
   ///
   /// Detailed description
   /// /return bool if the item was sucesfully used
   virtual bool use() = 0;

   /// \brief sets name
   ///
   void setName(std::string n) {name = n;};
   
   /// \brief sets description
   ///
   void setDescription(std::string n) {description = n;};

   /// \brief gets stats
   ///
   Attributes& getStats() {return stats;};

   /// \brief checks if weapon
   ///
   /// \return boolean telling whether it is weapon or not
   bool isWeapon()
   {
      int num = number;
      if (num == 0)
	 return true;
      else
	 return false;
   };

   /// \brief checks ifarmor
   ///
   /// \return boolean telling whether it is armor or not
   bool isArmor()
   {
      int num = number;
      if (num == 1)
	 return true;
      else
	 return false;
   };
   
    /// \brief checks if potion
   ///
   /// \return boolean telling whether it is potion or not
   bool isPotion()
   {
      int num = number;
      if (num == 2)
	 return true;
      else
	 return false;
   };

   /// \brief sets the number
   ///
   void setNum(int num) { number = num; }; 
	 
  private:
   int number;
   std::string name; 
   std::string description;
   Attributes stats;  
};

   /// \brief ostream operator
   ///
   /// param[in] - ostream operator - brought in
   /// param[in] - Item - item to be printed
   /// \return - ostream - return the ostream
std::ostream& operator<<(std::ostream &out, Item &I);
