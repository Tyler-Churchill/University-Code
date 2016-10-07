#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "Entity.h"

/// \brief Class RoomHall
///
class RoomHall : public Room
{
  public:
 
   /// \brief Generates the hall room
   ///
   /// This function generates which enemies will appear in the hall with player
   /// \param[in] none 
   /// \return void 
   void generate();
   
   /// \brief Gets the description for the hall room
   ///
   /// This function tells the user what is in and around the hall
   /// \param[in] none
   /// \return string-that describes the room's condition
   std::string getDescription();
   
   /// \brief Checks to see if the room enemies are in the hall room
   ///
   /// This function checks to see if anything is in the hall with player
   /// \param[in] none
   /// \return bool - true if the room is empty otherwise false
   bool isEmpty();
};
