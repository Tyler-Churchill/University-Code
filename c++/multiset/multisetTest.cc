//**************************************************************************
// CPSC2620 Spring 2014 Prof: Grant
// Assignment #2
// File: multisetTest.cc - test file for Multiset class
// Author: Arie
// Date: Feb. 8, 2014
// *************************************************************************
#include <iostream>
using namespace std;
  
#include "multiset.h"
 
int main()
{
   size_t amtRemoved;
   multiset m;
   
   cout << "Created empty Multiset m" << endl;
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;  
   
   cout << "Adding a 1 to m" << endl;
   m.insert(1);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;
   
   cout << "Adding 2 2's to m" << endl;
   m.insert(2, 2);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;

   cout << "Adding 3 3's to m" << endl;
   m.insert(3, 3);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;

   cout << "Adding 0 4's to m" << endl;
   m.insert(4, 0);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;
   
   
   cout << "Adding 2 5's to m" << endl;
   m.insert(5, 2);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;
   
   cout << "Adding 1 1's to m" << endl;
   m.insert(1);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;
  
   cout << "Adding 3 -1's to m" << endl;
   m.insert(-1,3);
   cout << "m.size() is " << m.size() << endl;
   cout << "m.unique() is " << m.unique() << endl;
   cout << m << endl << endl;
   
   
   cout << "Making p, a copy of m (assignment operator)" << endl;
   multiset p;
   p = m; // Here we tested the default assignment operator
   cout << "m = " << m << endl;
   cout << "p.size() is " << p.size() << endl;
   cout << "p.unique() is " << p.unique() << endl;
   cout << "p = " << p << endl << endl;
 
   p.removeAll(1);
   cout << "p.removeAll(1)" << endl;
   cout << "p.size() is " << p.size() << endl;
   cout << "p.unique() is " << p.unique() << endl;
   cout << "p = " << p << endl << endl;
  
   p.remove(2);
   cout << "p.remove(2)" << endl;
   cout << "p.size() is " << p.size() << endl;
   cout << "p.unique() is " << p.unique() << endl;
   cout << "p = " << p << endl << endl;

   amtRemoved = p.remove(2,2);
   cout << "p.remove(2,2)" << endl;
   cout << "p.size() is " << p.size() << endl;
   cout << "p.unique() is " << p.unique() << endl;
   cout << "actual amout removed is " << amtRemoved << endl;
   cout << "p = " << p << endl << endl;

   p.remove(3,2);
   cout << "p.remove(3,2)" << endl;
   cout << "p.size() is " << p.size() << endl;
   cout << "p.unique() is " << p.unique() << endl;
   cout << "p = " << p << endl << endl;
   
   amtRemoved = p.remove(3,15);
   cout << "p.remove(3,15)" << endl;
   cout << "actual amount removed is " << amtRemoved << endl;
   cout << "p = " << p << endl << endl;

   p.insert(8,4);
   cout << "p.insert(8,4)" << endl;
   cout << "p = " << p << endl << endl;
   
   cout << "*******************************************" << endl;
   cout << "m is " << m << endl;
   cout << "p is " << p << endl;
  
   cout << "Now performing p += m" << endl;
   p += m;
   cout << "m is " << m << endl;
   cout << "p is " << p << endl;
   cout << "********************************************" << endl << endl;

   cout << "Now performing m += p" << endl;
   m += p;
   cout << "p is " << p << endl;
   cout << "m is " << m << endl;
   cout << "********************************************" << endl << endl;
   
   // Testing the count function
   cout << "*****************************************************" << endl;
   cout << "Testing the count function for Multiset p" << endl;
   for(size_t i=0; i<p.unique(); i++)
      cout << "count of " <<  p(i) << " is " << p.count(p(i)) << endl;

   cout << "*****************************************************" << endl;
   cout << "Testing the contains function for Multiset p" << endl;
   cout << "p is: " << p << endl;
   if(p.contains(5))
      cout << "yup, p contains " << 5 << endl;
   else
      cout << "no, p does not contain " << 5 << endl << endl;
   if(p.contains(9))
      cout << "yup, p contains " << 9 << endl;
   else
      cout << "nope, p does not contain " << 9 << endl;
   cout << "*****************************************************" << endl;
   cout << endl;
  
   
   
   multiset m3;
   m3.insert(2,3);
   m3.insert(1,2);
   m3.insert(5,2);
   m3.insert(3,2);
   
   multiset m4;
   m4.insert(5,3);
   m4.insert(1,2);
   m4.insert(3,2);
   m4.insert(2,2);
   
   multiset m5;
   m5.insert(1,2);
   m5.insert(3,2);
   m5.insert(2,2);
   m5.insert(5,3);
   
   cout << boolalpha;
   cout << "*****************************************************" << endl;
   cout << "Testing the == function" << endl;
   cout << "Does " << m3 << " = " << m << "? " << (m3 == m) << endl;
   cout << "Does " << m4 << " = " << m3 << "? " << (m4 == m3) << endl;
   cout << "Does " << m4 << " = " << m5 << "? " << (m4 == m5) << endl;
   cout << "*****************************************************" << endl;
   
   cout << "*****************************************************" << endl;
   cout << "Testing the binary + function" << endl;
   multiset m6 = m4 + m5;
   cout << m4 << "+" << m5 << " is " << m6 << endl;
   cout << "*****************************************************" << endl;
   return 0;
   
}

