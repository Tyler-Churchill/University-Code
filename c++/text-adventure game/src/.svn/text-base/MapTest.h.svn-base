#pragma once 

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Map.h"
#include "EntityPlayer.h"
#include <algorithm>
#include <iostream>

class MapTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(MapTest);
   CPPUNIT_TEST(generation);
   CPPUNIT_TEST(isDescribed);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void tearDown();
   void generation();
   void isDescribed();

  private:
   EntityPlayer *player;
   Map *mapA;
   Map *map1a;
   Map *mapB;
   Map* map2;
   Map* map3;

   
};
