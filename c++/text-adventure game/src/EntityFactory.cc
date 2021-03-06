#include "Entity.h"
#include "EntityFactory.h"
#include <math.h>
#include "EntityBat.h"
#include "EntitySpider.h"
#include "EntitySkeleton.h"
#include "EntityTroll.h"
#include "Item.h"
#include <cstdlib>
#include "ItemFactory.h"
#include <time.h> 


EntityFactory *EntityFactory::__instance = nullptr;

EntityFactory* EntityFactory::getInstance()
{
   if (__instance == nullptr)
      __instance = new EntityFactory();
   return __instance;
}

Entity* EntityFactory::getEnemy(ENTITYTYPE e, Room *x)
{
   Entity* returnEntity = nullptr;
   int roomX = x->getX();
   int roomY = x->getY();
   std::string name;
   double scaleFactor;
   if(!(roomY == 0 && roomX == 0))
      scaleFactor = 2 / sqrt( pow(roomX, 2) + pow(roomY, 2));
   else
      scaleFactor = 1;
   int r;

   switch(e)
   {
      case BAT:
      {
//	 std::cout << "BAT CALLED" << std::endl;
	 Entity* returnEntity = new EntityBat();
	 r = rand() % 5 + 2;
	 name = "Bat";
	 returnEntity->setName(name);
	 returnEntity->setInventory(makeInventory(x));
	 returnEntity->getAttributes().setDamage(r * (1 + scaleFactor));
	 r = 1 + (rand() % (int) (4));
	 returnEntity->getAttributes().setVitality(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setHealthPoints(returnEntity->getAttributes().getVitality() * 10);
	 r = rand() % 5 + 4;
	 returnEntity->getAttributes().setAgility(r * (1 + scaleFactor));
	 r = rand() % 1 + 2;
	 returnEntity->getAttributes().setStrength(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setArmor(0);
	 
	 
	 return returnEntity;
      }
	 break;
      
      case SPIDER: 
      {
//	 std::cout << "SPIDER CALLED" << std::endl;
	 Entity* returnEntity = new EntitySpider();
	 r = rand() % 5 + 2;
	 name = "Spider" ;
          returnEntity->setName(name);
	  returnEntity->setInventory(makeInventory(x));
	 returnEntity->getAttributes().setDamage(r * (1 + scaleFactor));
	 r = 1 + (rand() % (int) (4));
	 returnEntity->getAttributes().setVitality(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setHealthPoints(returnEntity->getAttributes().getVitality() * 10);
	 r = rand() % 5 + 4;
	 returnEntity->getAttributes().setAgility(r * (1 + scaleFactor));
	 r = rand() % 1 + 2;
	 returnEntity->getAttributes().setStrength(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setArmor(0);
//	 std::cout << returnEntity->getAttributes().getHealthPoints() << std::endl;
	 return returnEntity;
      }
	 break;
      
      case TROLL :
      {
//	 std::cout << "TROLL CALLED" << std::endl;
	 Entity* returnEntity = new EntityTroll();
	 r = rand() % 5 + 2;
	 name = "Troll";
	 returnEntity->setName(name);
	 returnEntity->setInventory(makeInventory(x));
	 returnEntity->getAttributes().setDamage(r * (1 + scaleFactor));
	 r = 1 + (rand() % (int) (4));
	 returnEntity->getAttributes().setVitality(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setHealthPoints(returnEntity->getAttributes().getVitality() * 10);
	 r = rand() % 5 + 4;
	 returnEntity->getAttributes().setAgility(r * (1 + scaleFactor));
	 r = rand() % 1 + 2;
	 returnEntity->getAttributes().setStrength(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setArmor(0);
//	 std::cout << returnEntity->getAttributes().getHealthPoints() << std::endl;
	 return returnEntity;
      }
	 break;
      
      case SKELETON :
      {
//	 std::cout << "SKELETON CALLED" << std::endl;
	 Entity* returnEntity = new EntitySkeleton();
	 r = rand() % 5 + 2;
	 name = "Skeleton";
	 returnEntity->setName(name);

	 returnEntity->setInventory(makeInventory(x));
	 returnEntity->getAttributes().setDamage(r * (1 + scaleFactor));
	 r = 1 + (rand() % (int) (4));
	 returnEntity->getAttributes().setVitality(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setHealthPoints(returnEntity->getAttributes().getVitality() * 10);
	 r = rand() % 5 + 4;
	 returnEntity->getAttributes().setAgility(r * (1 + scaleFactor));
	 r = rand() % 1 + 2;
	 returnEntity->getAttributes().setStrength(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setArmor(0);
//	 std::cout << returnEntity->getAttributes().getHealthPoints() << std::endl;
	 return returnEntity;
      }
	 break;
      case DRAGON :
      {
	 //	 std::cout << "TROLL CALLED" << std::endl;
	 Entity* returnEntity = new EntityTroll();
	 r = rand() % 10 + 4;
	 name = "Mecha-Cheng";
	 returnEntity->setName(name);
	 returnEntity->setInventory(makeInventory(x));
	 returnEntity->getAttributes().setDamage(r * (1 + scaleFactor));
	 r = rand() % 10 + 4;
	 returnEntity->getAttributes().setVitality(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setHealthPoints(returnEntity->getAttributes().getVitality() * 10);
	 r = rand() % 10 + 4;
	 
	 returnEntity->getAttributes().setAgility(r * (1 + scaleFactor));
	  r = rand() % 10 + 4;
	 returnEntity->getAttributes().setStrength(r * (1 + scaleFactor));
	 returnEntity->getAttributes().setArmor(0);
//	 std::cout << returnEntity->getAttributes().getHealthPoints() << std::endl;
	 return returnEntity;
	 break;
      }
      case CONTAINER :
      {

	 break;
      }
	 
   }
   return returnEntity;
}


std::vector<Item*> EntityFactory::makeInventory(Room *x)
{
   std::vector<Item*> temp;
   
   int r = rand() % 3;
   switch(r)
   {   
      case 0 :
	 temp.push_back(ItemFactory::getInstance()->getItem(SWORD, x));
	 break;
      case 1 :
	 temp.push_back(ItemFactory::getInstance()->getItem(ARMOR, x));
	 break;
      case 2:
	 temp.push_back(ItemFactory::getInstance()->getItem(HEALTH_POTION, x));
	 break;
   }
   return temp;
}
