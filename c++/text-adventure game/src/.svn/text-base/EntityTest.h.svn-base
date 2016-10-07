#pragma once
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Entity.h"
#include "EntitySpider.h"
#include "EntityTroll.h"
#include "EntitySkeleton.h"
#include "EntityBat.h"
#include "EntityDragon.h"
#include "EntityFactory.h"
class EntityTester : public CppUnit::TestFixture
{
 
CPPUNIT_TEST_SUITE(IntVectorTest);
CPPUNIT_TEST(damageTest);
CPPUNIT_TEST(constructorTest);
CPPUNIT_TEST(lootTest);
CPPUNIT_TEST_SUITE_END();

/// \brief Sets up Entity objects to be used for testing
void setUp();

/// \brief Removes Entity objects that were to be used for testing
void tearDown();

/// \brief Tests that the constructors are working properly for all entity subclasses by checking the values. This is a unit test to make sure the objects recieve proper initial values
void constructorTest();
/// \brief Tests that loot will properly transfer between two entities. If an entity loots another entity, it should have no loot remaining , and the entity that looted it should have that loot contained within its invintory. This is a unittest
void lootTest();


Entity *spider; 
Entity *troll; 
Entity *skeleton;
Entity *dragon;
Entity *bat;
Room *room;


};

