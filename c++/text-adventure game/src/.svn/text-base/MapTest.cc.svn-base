#include <cppunit/extensions/HelperMacros.h>
#include "EntityPlayer.h"
#include "Map.h"
#include "MapTest.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

void MapTest::setUp()
{
   player = new EntityPlayer();
   mapA = new Map(1, player);
   mapB = new Map(1, player);
   map2 = new Map(2, player);
   map3 = new Map(3, player);
   map1a = new Map(1, player);
}

void MapTest::tearDown()
{
   delete map1a;
   delete mapA;
   delete mapB;
   delete map2;
   delete map3;	       
}


void MapTest::generation()			
{
   CPPUNIT_ASSERT(mapA->generate() && mapB->generate());
   std::cout << "All Maps passed generation" << std::endl;
}

void MapTest::isDescribed()
{
   CPPUNIT_ASSERT(mapA->generate());
   std::cout << "DESCRIBED PROPERLY" <<std::endl;
}

