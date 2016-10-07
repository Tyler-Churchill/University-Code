#include <cppunit/TextTestRunner.h>
#include <iostream>
#include "MapTest.h"
#include "ItemTest.h"
#include "GameTest.h"

int main() {

   // run all tests, run game test last
   std::cout << "Running tests for game" << std::endl << std::endl << std::endl;

   CppUnit::TextTestRunner runner;
   runner.addTest(MapTest::suite());
   runner.addTest(ItemTest::suite());
   //runner.addTest(GameTest::suite());
   runner.run();

  // record output to file
  // write a cronjob to run tester and email the output to people in the group

   return 0;
}
