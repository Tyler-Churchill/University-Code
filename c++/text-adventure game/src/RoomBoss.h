#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Entity.h"

/// \brief Class RoomBoss
///
class RoomBoss : public Room
{
  public:
   /// \brief Generates the boss room
   ///
   /// This function generates the boss that will appear in the boss room with player
   /// \param[in] none 
   /// \return void 
   void generate();
   
   /// \brief Gets the description for the boss room
   ///
   /// This function tells the user what is in and around the boss room 
   /// \param[in] none
   /// \return string-that describes the boss room's condition
   std::string getDescription();
   
   /// \brief Checks to see if the room enemies are in the boss room
   ///
   /// This function checks to see if anything is in the room with playe
   /// \param[in] none
   /// \return bool - true if the boss room is empty otherwise false
   bool isEmpty();
   
  private:
   // std::vector<*Entity> entities;
};
