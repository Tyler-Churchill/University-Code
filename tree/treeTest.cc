#include "tree.h"
#include <iostream>

using namespace std;
int main()
{
   cout << "Creating tree t with root 10" << endl;
   Tree<int> t(10);
   cout << "Tree t: "; t.print(); cout << endl;

// check contains and size
   cout << endl;
   cout << "Checking if t contains the 5: " << t.contains(5) << endl;
   cout << "Size of t: " << t.size() << endl;
   cout << "Adding 5 onto tree t" << endl;
   t.insert(5, 10);
   cout << "Tree t: "; t.print(); cout << endl;
   cout << "Size of t: " << t.size() << endl;
   cout << "Checking if t contains the 5: " << t.contains(5) << endl;


// check height
   cout << endl;
   cout << "Height of tree t: " << t.height() << endl;
   cout << "Adding 20 onto root 10" << endl;
   t.insert(20, 10);
   cout << "Tree t: "; t.print(); cout << endl;
   cout << "Height of tree t: " << t.height() << endl;
   cout << "Adding 1 onto node 5" << endl;
   t.insert(1, 5);
   cout << "Tree t: "; t.print(); cout << endl;
   cout << "Height of tree t: " << t.height() << endl;

// check remove
   cout << endl;
   cout << "Removing 5 from tree t" << endl;
   t.remove(5);
   cout << "Tree t: "; t.print(); cout << endl;


// check copy
   cout << endl;
   cout << "Copying tree t into tree z" << endl;
   Tree<int> z(t);
   cout << "Tree z: "; z.print(); cout << endl;

// check =
   cout << endl;
   Tree<int> a(5);
   a.insert(20, 5);
   a.insert(25, 5);
   a.insert(1, 25);
   cout << "Making tree a = tree z" << endl;
   cout << "Tree a: "; a.print(); cout << endl;
   cout << "Tree a = z" << endl;
   a = z;
   cout << "Tree a: "; a.print(); cout << endl;

   return 0;
}
