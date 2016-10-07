// Item Test.h
//

#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
#include <algorithm>
#include "Item.h"

class ItemTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(ItemTest);
   CPPUNIT_TEST(isUsed);
   CPPUNIT_TEST(properDescription);
   CPPUNIT_TEST(properName);
   CPPUNIT_TEST(isRightItem); 
   CPPUNIT_TEST_SUITE_END();

  public:
   /// \brief create the Items
   ///
   void createItem();

   /// \brief destruct items created
   ///
   void destructItem();

   /// \brief check to see if item is actually used properly
   ///
   void isUsed();

   /// \brief check to see if the proper description is returned
   ///
   void properDescription();

   /// \brief check to see if the proper item name is returned
   ///
   void properName();

   /// \brief check to see if its the right item
   ///
   void isRightItem();

  private :
   Room *room;
   Item *pot1;
   Item *pot2;
   Item *armor1;
   Item *sword1;
   
};
