#include "EntityPlayer.h"
#include "ItemFactory.h"
#include "Weapon.h"
#include "Armor.h"
#include <math.h> 
#include <stdlib.h>
EntityPlayer::EntityPlayer()
{
   Item *q = new Weapon;
   Item *j = new Armor;
   
   q->getStats().setArmor(0);
   q->getStats().setVitality(0);
   q->getStats().setAgility(0);
   q->getStats().setStrength(0);
   q->getStats().setDamage(0);
   q->getStats().setHealthPoints(0);
   
   j->getStats().setArmor(0);
   j->getStats().setVitality(0);
   j->getStats().setAgility(0);
   j->getStats().setStrength(0);
   j->getStats().setDamage(0);
   j->getStats().setHealthPoints(0);
   

   
   equippedWeapon = q;
   equippedArmor = j;
}
EntityPlayer::~EntityPlayer()
{
   delete equippedWeapon;
   delete equippedArmor;
   delete[] q;
   delete[] j;
}
bool EntityPlayer::attack(Entity &entity)
{
   srand (time(NULL));
   double dodgeChance = log10(entity.getAttributes().getAgility())/4;
   dodgeChance = dodgeChance * 100;
   double r = rand() % 101;
   
   if(r <= dodgeChance)
      return false;
   else
   {
      int damageRange = rand() % 5 + (getAttributes().getDamage()) - 2;
      double damageDealt = (((getAttributes().getStrength() * 0.05) + 1) * damageRange) * (10/(10-entity.getAttributes().getArmor()));
      entity.getAttributes().setHealthPoints(entity.getAttributes().getHealthPoints() - damageDealt);
   }
   getLoot(entity);
   return true;
}

bool EntityPlayer::isAlive()
{
   if (getAttributes().getHealthPoints() <= 0)
      return false;
   else
      return true;


}
void EntityPlayer::getLoot(Entity &entity)
{
   if((entity.isAlive()))
   {
      return;
   }
   else
   {
      std::cout << "GETLOOT CALLED" << std::endl;
//      std::vector<Item*> temp = entity.getInventory();
      std::vector<Item*> temp2 = this->getInventory();
      std::vector<Item*> empty;
      for(size_t i = 0; i < entity.getInventory().size(); i++)
	 temp2.push_back(entity.getInventory()[i]);
      this->setInventory(temp2);
      entity.setInventory(empty);	 
   }
}

bool EntityPlayer::hasLoot()
{
   if(getInventory().size() > 0 )
      return true;
   else return false;

}
void EntityPlayer::equipWeapon(Item *item)
{
   int currHealth;
   int weaponHealth;
   int weaponStrength;
   int currStrength;
   int currVitality;
   int weaponVitality;
   int currAgility;
   int weaponAgility;
   int currArmor;
   int weaponArmor;
   int currDamage;
   int weaponDamage;
 
   //Health Points
    currHealth = this->getAttributes().getHealthPoints();
    weaponHealth = equippedWeapon->getStats().getHealthPoints();
   this->getAttributes().setHealthPoints(currHealth-weaponHealth);
   //Strength
    currStrength = this->getAttributes().getStrength();
  
    weaponStrength = equippedWeapon->getStats().getStrength();
   this->getAttributes().setStrength(currStrength-weaponStrength);
   //Vitality
    currVitality = this->getAttributes().getVitality();
   
    weaponVitality = equippedWeapon->getStats().getVitality();
   this->getAttributes().setVitality(currVitality-weaponVitality);
   //Agility
    currAgility = this->getAttributes().getAgility();
   
   weaponAgility = equippedWeapon->getStats().getAgility();
   this->getAttributes().setAgility(currAgility-weaponAgility);
   //Armor
    currArmor = this->getAttributes().getArmor();
   
    weaponArmor = equippedWeapon->getStats().getArmor();
   this->getAttributes().setArmor(currArmor-weaponArmor);
   //Damage
    currDamage = this->getAttributes().getDamage();

    weaponDamage = equippedWeapon->getStats().getDamage();
   this->getAttributes().setDamage(currDamage-weaponDamage);
   
   equippedWeapon = item;

    //Health Points
    currHealth = this->getAttributes().getHealthPoints();
    weaponHealth = equippedWeapon->getStats().getHealthPoints();
   this->getAttributes().setHealthPoints(currHealth+weaponHealth);
   //Strength
    currStrength = this->getAttributes().getStrength();
  
    weaponStrength = equippedWeapon->getStats().getStrength();
   this->getAttributes().setStrength(currStrength+weaponStrength);
   //Vitality
    currVitality = this->getAttributes().getVitality();
   
   weaponVitality = equippedWeapon->getStats().getVitality();
   this->getAttributes().setVitality(currVitality+weaponVitality);
   //Agility
   currAgility = this->getAttributes().getAgility();
   
    weaponAgility = equippedWeapon->getStats().getAgility();
   this->getAttributes().setAgility(currAgility+weaponAgility);
   //Armor
    currArmor = this->getAttributes().getArmor();
   
    weaponArmor = equippedWeapon->getStats().getArmor();
   this->getAttributes().setArmor(currArmor+weaponArmor);
   //Damage
    currDamage = this->getAttributes().getDamage();

    weaponDamage = equippedWeapon->getStats().getDamage();
   this->getAttributes().setDamage(currDamage+weaponDamage);
}

void EntityPlayer::usePotion(Item *item, int x)
{
   int currHealth = this->getAttributes().getHealthPoints();
   int potionHealth = item->getStats().getHealthPoints();
   int maxHealth=(10 * getAttributes().getVitality());
     
   std::cout<<currHealth<<std::endl<<potionHealth<<std::endl;
   std::cout<<(currHealth + potionHealth)<<"  "<< (getAttributes().getVitality());

   if (currHealth==maxHealth)
   {
      std::cout<<"at full";
      return;
   }
   if((currHealth + potionHealth) < maxHealth)
   {
      this->getAttributes().setHealthPoints(currHealth + potionHealth);
   }
   else
   {
      getAttributes().setHealthPoints(maxHealth);
   }
   getInventory().erase(getInventory().begin() + x); 
}

void EntityPlayer::equipArmor(Item *item)
{
   int currHealth;
   int armorHealth;
   int armorStrength;
   int currStrength;
   int currVitality;
   int armorVitality;
   int currAgility;
   int armorAgility;
   int currArmor;
   int armorArmor;
   int currDamage;
   int armorDamage;
   
   
   //Health Points
      currHealth =  getAttributes().getHealthPoints();
    armorHealth = equippedArmor->getStats().getHealthPoints();
   
   this->getAttributes().setHealthPoints(currHealth-armorHealth);
   //Strength
    currStrength = this->getAttributes().getStrength();
    armorStrength = equippedArmor->getStats().getStrength();
 
   this->getAttributes().setStrength(currStrength-armorStrength);
   //Vitality
    currVitality = this->getAttributes().getVitality();
    armorVitality = equippedArmor->getStats().getVitality();
   
   this->getAttributes().setVitality(currVitality-armorVitality);
   //Agility
    currAgility = this->getAttributes().getAgility();
    armorAgility = equippedArmor->getStats().getAgility();
   
   this->getAttributes().setAgility(currAgility-armorAgility);
   //Armor
    currArmor = this->getAttributes().getArmor();
    armorArmor = equippedArmor->getStats().getArmor();

   this->getAttributes().setArmor(currArmor-armorArmor);
   //Damage
    currDamage = this->getAttributes().getDamage();
    armorDamage = equippedArmor->getStats().getDamage();
   this->getAttributes().setDamage(currDamage-armorDamage);
   
   equippedArmor = item;

    //Health Points
    currHealth = this->getAttributes().getHealthPoints();
    armorHealth = equippedArmor->getStats().getHealthPoints();
   
   this->getAttributes().setHealthPoints(currHealth+armorHealth);
   //Strength
    currStrength = this->getAttributes().getStrength();
    armorStrength = equippedArmor->getStats().getStrength();
 
   this->getAttributes().setStrength(currStrength+armorStrength);
   //Vitality
    currVitality = this->getAttributes().getVitality();
    armorVitality = equippedArmor->getStats().getVitality();
   
   this->getAttributes().setVitality(currVitality+armorVitality);
   //Agility
    currAgility = this->getAttributes().getAgility();
    armorAgility = equippedArmor->getStats().getAgility();
   
   this->getAttributes().setAgility(currAgility+armorAgility);
   //Armor
    currArmor = this->getAttributes().getArmor();
    armorArmor = equippedArmor->getStats().getArmor();

   this->getAttributes().setArmor(currArmor+armorArmor);
   //Damage
    currDamage = this->getAttributes().getDamage();
    armorDamage = equippedArmor->getStats().getDamage();
   this->getAttributes().setDamage(currDamage+armorDamage);
}
