#pragma once
 
#include <string>
#include "Map.h"
#include "EntityPlayer.h"

///
/// /brief Game class
///
class Game
{
  public:
   /// \brief game destructor
   ///
   ~Game();

   /// \brief Initializes and starts a new game
   void start();

   /// \brief Asks user details to create their character
   void createCharacter();
  
   /// \brief Generates the game map and sets the generated map to the current game map
   bool generateMap();

   /// \brief Main loop of the game, responsible for updating game logic/game world
   void mainLoop();

   /// \brief checks the rooms options
   ///
   void roomOption();
   
   /// \brief checks the combat choices of the room
   ///
   void combat(Room *room);

   /// \brief checks the inventory of the player
   ///
   void inventory();
   
   /// \brief Displays the avaliable options that the user has in each room based on player state
   void displayOptions();

   /// \brief Displays the users inventory to the screen
   ///
   /// \param[inout] player, the player you wish to display inventory of
   void openInventory(EntityPlayer &player);

   /// \brief Asks the user for a integer input
   ///
   /// \return Returns the option the user picked
   int getOption();

   /// \brief Outputs the given text to the screen
   ///
   /// \param[in] Text to be outputed to the screen
   void print(std::string text);

   /// \brief Returns the difficulty of the game
   ///
   /// \return Returns the difficulty of the game
   int getDifficulty() const;

   /// \brief sets the difficulty of the game
   ///
   /// \param[in] difficulty, the difficulty you want to set the game to (1 - 3)
   void setDifficulty(int difficulty);

   /// \brief logs a debug message to the console
   ///
   /// \param[in] message to log to console
   void log(std::string message);

   /// \brief sets debug messages on or off 
   ///
   /// \paramin[in] the toggle on or off
   void setDebug(bool d);

   /// \brief gets the current debug state on or off
   ///
   /// \return bool, true if on false if off
   bool getDebug() const;

   /// \brief Exits the game safely
   ///
   void exit();

   /// \brief Clears the console screen
   ///
   void clear();
  
  private:
   Map *map = nullptr;
   EntityPlayer *player = nullptr;
   bool isRunning = false;
   bool debug = false;
   int difficulty = 1;
};
