#pragma once

#include "Item.h"
#include "Room.h"

/// \brief ItemFactory class for creation of weapons, armor, and potions.
///
class ItemFactory
{
   static ItemFactory* __instance;

  public:
   virtual ~ItemFactory(){
      delete this;
   };
   /// \brief Gets current instance of the item factory
   ///
   /// \return ItemFactory, the current instance of the item factory
   static ItemFactory* getInstance();

   /// \brief Creates a item based on the given type and level
   /// Detailed description
   /// \param[in] ItemType, the type of item you want to create
   /// \param[in] level, Integer passed in by room to determine the power of the item   
   Item* getItem(ITEMTYPE i, Room *roomIn);
  private:
   std::string swordName[5]= {"Lightbringer", "Hunter's Machete", "Dagger", "Bloodthirster", "Void Staff"};
   std::string armorName[5] = {"Defender", "Square Plate", "War Plate", "Chain Plate", "Master Plate"} ;
   std::string swordDec[5] = {"Lightbringer shines bright with energy",
			   "Hunter's Machete Was Used By Your Forefathers To Hunt The Mighty Beasts",
			   "Basic Dagger, Nothing Too Fancy. But Who Needs That?",
			   "Bloodthirster Seeks What It Says",
			   "Void Staff Was Crafted In The Darkest Parts Of The World, Its Shaft Is Sturdy!"};
   std::string armorDec[5] = {"Defender Has Defended Those Who Fight For Generations",
			    "Square Plate Is As Basic As It Says, A Simple Square Like Body Made Of Strong Metal",
			    "War Plate Was Crafted By The Gods To Protect Anything That Was Honorable",
			    "Chain Plate Is A Strong Body Weaved With Chains",
			      "Master Plate Was Given Only To Those Who Become Master's In The Field Of Assassination. Small, But Manouverable"};
   std::string potionDec = "Health Potion For The Wounds";
   std::string potionName = "Health Pot";
};
