
#pragma once

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Game.h"

class GameTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(GameTest);
   CPPUNIT_TEST(testMapWorks);
   CPPUNIT_TEST_SUITE_END();

  public:
   void setUp();
   void testMapWorks();
   void tearDown();

  private:
   Game* game;

};
