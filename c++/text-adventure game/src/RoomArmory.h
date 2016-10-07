#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Entity.h"

/// \brief Class RoomArmory
///
class RoomArmory : public Room
{
  public:
   
   /// \brief Generates the armory room
   ///
   /// This function generates which enemies will appear in the armory with player
   /// \param[in] none 
   /// \return void 
   void generate();
   
   /// \brief Gets the description for the armory room
   ///
   /// This function tells the user what is in and around the armory
   /// \param[in] none
   /// \return string-that describes the armory's condition
   std::string getDescription();
   
   /// \brief Checks to see if the room enemies are in the armory room
   ///
   /// This function checks to see if anything is in the armory with player
   /// \param[in] none
   /// \return bool - true if the armory is empty otherwise false
   bool isEmpty();
};
