#include <cppunit/extensions/HelperMacros.h>
#include "Game.h"
#include "GameTest.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

void GameTest::setUp()
{
   game = new Game();
}

void GameTest::tearDown()
{
   delete game;
}

void GameTest::testMapWorks()
{
   CPPUNIT_ASSERT(game->generateMap());
   cout << "Map generates correctly" << endl;
}
