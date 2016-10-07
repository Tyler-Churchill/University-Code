#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Entity.h"
#include "EntitySpider.h"
#include "EntityTroll.h"
#include "EntitySkeleton.h"
#include "EntityBat.h"
#include "EntityDragon.h"
#include "EntityTest.h"
#include "EntityFactory.h"
#include "Room.h"
#include "RoomStandard.h"

void EntityTester::setUp()
{
   room->setX(5);
   room->setY(5);
   spider = EntityFactory::getInstance()->getEnemy(SPIDER, room);
   troll = EntityFactory::getInstance()->getEnemy(TROLL, room);
   bat = EntityFactory::getInstance()->getEnemy(BAT, room);
   dragon = EntityFactory::getInstance()->getEnemy(DRAGON, room);
   skeleton = EntityFactory::getInstance()->getEnemy(SKLETON, room);
}

void EntityTester::tearDown()
{
   delete room;
   delete spider;
   delete troll;
   delete bat;
   delete dragon;
   delete skeleton;
}

void EntityTester::constructorTest()
{
   CPPUNIT_ASSERT(spider->isAlive());
   CPPUNIT_ASSERT(troll->isAlive());
   CPPUNIT_ASSERT(bat->isAlive());
   CPPUNIT_ASSERT(dragon->isAlive());
   CPPUNIT_ASSERT(skeleton->isAlive());

}

void EntityTester::lootTest()
{
   while (troll->hasLoot())
      spider->getLoot(troll);

   CPPUNIT_ASSERT((spider->hasLoot()) && (!(troll->hasLoot())));

}
