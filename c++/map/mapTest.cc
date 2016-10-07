/**
 *  Author: Tyler Churchill
 *  This map stores key/value pairs and grows to the size you need
 */

#include "map.h"
#include <iostream>

using namespace std;

int main()
{

   map one;
   one.insert("bb", 50);
   one.insert("aa", 152);
   one.insert("zz", 763);
   
   cout << endl << "Map one: " << one << endl;

   // copy test
   cout << endl << "Copying map one into map two" << endl;
   map two(one);
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;

   // insert test
   cout << endl << "Inserting Hello into map one with value 120" << endl;
   one.insert("Hello", 120);
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;

   // asignment test
   cout << endl << "Assigning map two to map one" << endl;
   two = one;
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;

   // find value test
   cout << endl << "Finding value of key Hello in map two" << endl;
   cout << "Value of Hello: " << *two.find("Hello") << endl;

   // equals test
   cout << endl << "Does map one equal map two" << endl;
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;
   bool a = one == two;
   cout << "Maps equal: " << a << endl;
   cout << "Inserting What to map two with value of 123" << endl;
   two.insert("What", 123);
   bool b = one == two;
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;
   cout << "Maps equal: " << b << endl;

   // addition test
   map three = one + two;
   cout << endl << "Adding map one and map two into map three" << endl;
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;
   cout << "Map three: " << three << endl;

   // erase test
   cout << endl << "Erasing Hello from map three" << endl;
   three.erase("Hello");
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;
   cout << "Map three: " << three << endl;

   // clearing map three
   cout << endl << "Clearing map three" << endl;
   three.clear();
   cout << "Map one: " << one << endl;
   cout << "Map two: " << two << endl;
   cout << "Map three: " << three << endl;

   // <= test
   cout << endl << "Seeing if map one is a subset of map two" << endl;
   bool c = one <= two;
   cout << "Map one subset of map two: " << c << endl;

   
   return 0;
}
