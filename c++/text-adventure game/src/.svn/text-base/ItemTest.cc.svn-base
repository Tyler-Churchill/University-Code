// Item Test.cc
//

#include <iostream>
#include <cppunit/extensions/HelperMacros.h>
#include <algorithm>
#include <stdexcept>
#include "ItemFactory.h"
#include "ItemTest.h"
#include "Item.h"
#include "Room.h"
#include "RoomStandard.h"

void ItemTest::createItem()
{
   room = new RoomStandard();
   room->setX(5);
   room->setY(5);
   pot1 = ItemFactory::getInstance()->getItem(HEALTH_POTION, room);
   pot2 =  ItemFactory::getInstance()->getItem(HEALTH_POTION, room);
   armor1 = ItemFactory::getInstance()->getItem(ARMOR, room);
   sword1 =  ItemFactory::getInstance()->getItem(SWORD, room);
}

void ItemTest::destructItem()
{
   delete pot1;
   delete pot2;
   delete armor1;
   delete sword1;
}

void ItemTest::isUsed()
{
   CPPUNIT_ASSERT(pot1->use());
   std::cout << "Item Properly Used" << std::endl;
}

void ItemTest::properDescription()
{
   CPPUNIT_ASSERT(!pot2->getDescription().empty());
   std::cout << "Descritpion Returned" << std::endl;
}

void ItemTest::properName()
{
   CPPUNIT_ASSERT(!pot2->getName().empty());
   std::cout << "Name Returned" << std::endl;
}

void ItemTest::isRightItem()
{
   CPPUNIT_ASSERT(armor1->isWeapon());
   std::cout << "Yes It Is Armor" << std::endl;
}
