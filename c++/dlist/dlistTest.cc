//****************************************************************************
// CPSC2620 Spring 2012 Prof: Grant
// Assignment #4
// Purpose: To design and create a DOUBLY LINKED CIRCULAR LIST w/ dummy header
// File: dListTest.cc - client test file sList class
// Written by: Arie
// Date: April 6, 2012
// ***************************************************************************

#include"dlist.h"
#include<iostream>
using namespace std;

int main()
{
   dlist_const_iterator<int> it;
   dlist<int> l1;
  
   l1.push_back(3);
   l1.push_back(5);
   l1.push_back(15);
   l1.push_back(23);
   l1.push_back(351);
   l1.push_back(-18);
 
   
   cout << "l1 after 6 push back is: " << l1 << endl;
    cout << "l1[2] = " << l1[2] << endl;
   l1.pop_back();
   cout << "l1 after pop_back(): " << l1 << endl;
   it = l1.begin();
    it++;  // --it;
   cout << "it = l1.begin(); it++;  *it = " << *it << endl << endl;
 
   cout << "l1 find[2]" << l1[2] << endl;
   dlist<int> l2(l1);
   cout << "after dlist<int> l2(l1) l2 is: " << l2 << endl;
   
   cout << "l2[0] = " << l2[0] << endl << endl;

   l2.push_back(-5);
   l2.push_back(97);
   l2.push_back(-12);

   cout << "after 3 push_backs l2 is:      " << l2 << endl;
   cout << "Changing 3rd value in l2 to -13" << endl;
   l2[2] = -13;
   cout <<"\tl2 is now:             " << l2 << endl << endl;

  


   cout << "l1: " << l1 << endl;
   cout << "l2: " << l2 << endl;
   l1 += l2;
   cout << "after l1 += l2, l1 is: " << endl; 
   
   cout << '\t' << l1 << endl<< endl;
   
   cout << "l1 size is " << l1.size() << endl << endl;	

   cout << "l2 is: " << l2 << endl << endl;  
   
   cout << "inserting into 6th posn of l2 with insert(5,-28) " << endl;
   l2.insert(5,-28);
   cout << "    l2 is: " << l2 << endl << endl;
   cout << "inserting into 2nd posn of l2 with insert(1,22) " << endl;
   l2.insert(1,22);
   cout << "    l2 is: " << l2 << endl << endl;
   cout << "inserting into 6th posn of  l2 with insert(5,57) " << endl;
   l2.insert(5,57);
   cout << "    l2 is: " << l2 << endl << endl;
   cout << "inserting into 4th posn of l2 with insert(3,292) " << endl;
   l2.insert(3,292);
   cout << "    l2 is: " << l2 << endl << endl;
   cout << "inserting into 13th posn of l2 with insert(12,14) " << endl;
   l2.insert(12, 14);
   cout << "    l2 is: " << l2 << endl << endl;
   cout << "inserting into 101st posn of l2 with insert(100,-99) " << endl;
   l2.insert(100,-99);
   cout << "    l2 is now: " << l2 << endl << endl;

   l2.erase(1);
   cout << "l2 after erase 2nd element: "<< endl;
   cout << "    l2 is: " << l2 << endl << endl;
   
   l2.erase(6);
   cout << "l2 after erase 7th element:" << endl;
   cout << "    l2 is: " << l2 << endl << endl;
   
   l2.erase(l2.size() - 1);
   cout << "l2 after erase last element:" << endl;
   cout << "    l2 is: " << l2 << endl << endl;

   cout << "element l2.back() is " << l2.back() << endl<< endl;

   const dlist<int> l3(l1);
   cout << "const dlist<int> l3(l1);"<<endl;
   cout << "    l3 is: " << l3 << endl << endl;
   
   cout << "l3.back() is " << l3.back() << endl << endl;
   
   cout << "l3[1] is: " << l3[1] << endl << endl;
   
   cout << "Creating a new empty list l4" << endl;
   dlist<int> l4;
   cout << "printing l4 is: " << l4 << endl;
   cout << "l4.back() is " << l4.back() << endl << endl;
   
   cout << "l3 is " << l3 << endl;
   cout << "l3 in reverse is: ";
   print_reverse(l3);
   cout << endl << endl;
    cout << "Creating a new list l5, a reverse copy of l2" << endl;
   cout << "l2 is " << l2 << endl;
     dlist<int> l5 = reverse(l2);
     cout << "l5 is " << l5 << endl;

   return 0;
}
