// Item.cc
//

#include "Item.h"

std::ostream& operator<<(std::ostream &out, Item &I)
{
   out << "Item Name : " << I.getName() <<std::endl;
   out << "\nStrength  : " << I->getStats().getStrength() <<std::endl;
   out << "\nVitality  : " << *I->getStats().getVitality() <<std::endl;
   out << "\nAgility   : " << *I->getStats().getAgility() <<std::endl;
   out << "\nHealth    : " << *I->getStats().getHealthPoints() <<std::endl;
   out << "\nArmor     : " << *I->getStats().getArmor() <<std::endl;
   out << "\nDamage    : " << *I->getStats().getDamage() <<std::endl;
   return out;
}
