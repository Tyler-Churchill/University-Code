#include "ItemFactory.h"
#include <cstdlib>
#include <ctime>
#include "math.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Room.h"

ItemFactory *ItemFactory::__instance = nullptr;


ItemFactory* ItemFactory::getInstance()
{
   if(__instance == nullptr)
      __instance = new ItemFactory();
   return __instance;
}

Item* ItemFactory::getItem(ITEMTYPE i, Room *roomIn)
{
   int roomX = roomIn->getX();
   int roomY = roomIn->getY();
   double level;
   level = 10 / sqrt(pow(roomX, 2) + pow(roomY, 2));

   switch(i)
   {
      case SWORD :
      {
	 Item *swordMade = new Weapon(); //creates sword
	 int randVar = (int) rand() % 4; // random number to search array
	 swordMade->setNum(0);
	 switch (randVar)
	 {
	    case 0 :
	    {
	       swordMade->getStats().setDamage((int) (rand() % 7 + level)); // created Lightbringer, sets damage
	       swordMade->getStats().setVitality((int) (rand() % 1 + 7)); // add some health stats
	    }
	       break;
	    case 1 :
	    {
	       swordMade->getStats().setDamage((int) (rand() % 4 + level)); // Created Hunter's Machete, sets damage
	       swordMade->getStats().setAgility((int) (rand() % 4 + 1)); // sets agility to machete
	    }
	       break;
	    case 2 :
	    {
	       swordMade->getStats().setDamage((int) (rand() % 3 + level)); // Created Dagger, sets damage
	       swordMade->getStats().setAgility((int) (rand() % 5 + 1)); // sets agility to dagger
	    }
	       break;
	    case 3 :
	    {
	       swordMade->getStats().setDamage((int) (rand() % 5 + level)); // Created Bloodthirster, sets damage
	       swordMade->getStats().setVitality((int) (rand() % 3 + 5)); // add some health stats
	    }
	       break;
	    case 4 :
	    {
	       swordMade->getStats().setDamage((int) (rand() % 4 + level)); // Created Void Staff, sets damage
	       swordMade->getStats().setAgility((int) (rand() % 5 + 1)); // sets agility to staff
	       swordMade->getStats().setVitality((int) (rand() % 5 + 3)); // add some health stats
	    }
	       break;
	 }
	 swordMade->setName(swordName[randVar]); // sets sword name to selected weapon
	 swordMade->setDescription(swordDec[randVar]); // sets description based off sword
	 return swordMade;
      }
	 break;

      case ARMOR :
      {
	 Item *armorMade = new Armor(); // creates a plate
	 int randVar = (int) rand() % 4; // randomly selects a plate from array
	 armorMade->setNum(1);
	 switch (randVar)
	 {
	    case 0 :
	    {
	       armorMade->getStats().setArmor((int) (rand() % 3 + level)); // sets armor for defender
	       armorMade->getStats().setVitality((int) (rand() % 2 + level)); // sets health bonus for defender
	    }
	       break;
	    case 1 :
	    {
	       armorMade->getStats().setArmor((int) (rand() % 6 + level)); // sets armor for square plate
	       armorMade->getStats().setVitality((int) (rand() % 2 + level)); // sets health bonus for square plate
	    }
	       break;	    
	    case 2 :
	    {
	       armorMade->getStats().setArmor((int) (rand() % 5 + level)); // sets armor for war plate
	       armorMade->getStats().setVitality((int) (rand() % 5 + level)); // sets health bonus for war plate
	    }
	       break;
	    case 3 :
	    {
	       armorMade->getStats().setArmor((int) (rand() % 4 + level)); // sets armor for chain
	       armorMade->getStats().setVitality((int) (rand() % 3 + level)); // sets health bonus for chain
	    }
	       break;
	    case 4 :
	    {
	       armorMade->getStats().setArmor((int) (rand() % 7 + level)); // sets armor for master armor
	       armorMade->getStats().setVitality((int) (rand() % 4 + level)); // sets health bonus for master armor
	    }
	       break;
	 }
	 armorMade->setName(armorName[randVar]); // sets armor name based on selected
	 armorMade->setDescription(armorDec[randVar]); // sets description based on armor selected
	 return armorMade;
      }
      break;

      case HEALTH_POTION :
      {
	 Item *healthPotMade = new Potion(); // creates a health pot
	 int randVar = 10 + (level * 2); // creates a number that is acceptable for the pot based on level
	 healthPotMade->setNum(2);
	 healthPotMade->getStats().setHealthPoints(randVar); // sets health points to number calculated 
	 healthPotMade->setName(potionName); // sets potion name
	 healthPotMade->setDescription(potionDec); // sets potion description
	 return healthPotMade;
      }
	 break;

      default :
      {
	 std::cout << "Invalid Item, Item Not Created" <<std::endl;
	 return 0;
      }
   }
}
