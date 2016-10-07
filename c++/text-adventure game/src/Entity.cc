#include "Entity.h"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const Entity& e)
{
   os << "Attributes: \nHealth: " << e.getAttributes().getHealthPoints()
      << "\nVitality: " << e.getAttributes().getVitality()
      << "\nAgility: " << e.getAttributes().getAgility()
      << "\nStrength: " << e.getAttributes().getStrength()
      << "\nDamage: " << e.getAttributes().getDamage()
      << "\nArmor: " << e.getAttributes().getArmor() << std::endl << std::endl;
   return os;
}
