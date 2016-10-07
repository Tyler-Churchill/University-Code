
#include "EntityBat.h"
#include <math.h> 
#include <stdlib.h>

bool EntityBat::attack(Entity &entity)
{
   double dodgeChance = log10(entity.getAttributes().getAgility())/4;
   dodgeChance = dodgeChance * 100;
   double r = rand() % 101;

   //  std::cout << "Dodge : " << dodgeChance << " Range : " << r << std::endl;

   if(r <= dodgeChance)
   {
      // std::cout << "MISSED" << std::endl;
      return false;
   }
   else
   {
      int damageRange = rand() % 5 + (getAttributes().getDamage()) - 2;
      double damageDealt = (((getAttributes().getStrength() * 0.05) + 1) * damageRange) * (10/(10-entity.getAttributes().getArmor()));
      entity.getAttributes().setHealthPoints(entity.getAttributes().getHealthPoints() - damageDealt);
      getAttributes().setHealthPoints(getAttributes().getHealthPoints() + (0.25 * damageDealt));
   }
   return true;
}
   

bool EntityBat::isAlive()
{
   if (getAttributes().getHealthPoints() <= 0)
      return false;
   else
      return true;
}
void EntityBat::getLoot(Entity &entity)
{
   for(int x = entity.getInventory().size()-1; entity.hasLoot(); x--)
   {
      
      getInventory().push_back(entity.getInventory()[x]);
      entity.getInventory().pop_back();
   }
}
bool EntityBat::hasLoot()
{
   if(getInventory().size() > 0 )
      return true;
   else return false;

}
void EntityBat::update()
{


}

