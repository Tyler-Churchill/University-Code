#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "Room.h"
#include "EntityFactory.h"

/// \brief Class RoomStandard
///
class RoomStandard : public Room
{
  public:
   /// \brief Generates the standard room
   ///
   /// This function generates which enemies will appear in the room with player
   /// \param[in] none 
   /// \return void 
   void generate();
   
   /// \brief Gets the description for the standard room
   ///
   /// This function tells the user what is in and around the room 
   /// \param[in] none
   /// \return string-that describes the room's condition
   std::string getDescription();
   
   /// \brief Checks to see if the room enemies are in the standard room
   ///
   /// This function checks to see if anything is in the room with player
   /// \param[in] none
   /// \return bool- true if the room is empty otherwise false 
   bool isEmpty();
   
  
};
