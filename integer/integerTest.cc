#include <iostream>
#include <string>
  using namespace std;
  
#include "integer.h"

int main(int argc, char **argv) {

  Integer x, y;
  string sy;

  cout << "Please enter two integers, separated by a space: ";
  cin >> x >> sy;

  y = Integer(sy);
  
  cout << "x = " << x << endl;
  
  cout << "Size of x = " << x.size() << endl;
  
  for (int i = 0; i < x.size(); i++)
    cout << "x[" << i << "]=" << x[i] << endl;
  
  cout << "y = " << y << endl;
  
  x += y;
  
  cout << "Performed x += y, x = " << x << endl;
  
  y = ++x;
  
  cout << "Performed y = ++x, x = " << x << ", y = " << y << endl;

  y = x++;
  
  cout << "Performed y = x++, x = " << x << ", y = " << y << endl;
  
  x <<= 26;
  
  cout << "Left-shifted x by 26, x = " << x << endl;
  
  Integer z = x;
  
  x >>= 26;
  
  cout << "Right-shifted x by 26, x = " << x << endl;

  cout << x << " + " << y << " = " << (x+y) << endl;
  
  cout << z << " + " << z << " = " << (z+z) << endl;
  
  cout << x << " << " << 5 << " = " << (x << 5) << endl;
  
  cout << x << " >> " << 1 << " = " << (x >> 1) << endl;
  
  cout << boolalpha;
  
  cout << x << "==" << x << " = " << (x == x) << endl;
  cout << x << "!=" << x << " = " << (x != x) << endl;
  cout << x << "<"  << x << " = " << (x <  x) << endl;
  cout << x << "<=" << x << " = " << (x <= x) << endl;
  cout << x << ">"  << x << " = " << (x >  x) << endl;
  cout << x << ">=" << x << " = " << (x >= x) << endl;
  
  cout << x << "==" << y << " = " << (x == y) << endl;
  cout << x << "!=" << y << " = " << (x != y) << endl;
  cout << x << "<"  << y << " = " << (x <  y) << endl;
  cout << x << "<=" << y << " = " << (x <= y) << endl;
  cout << x << ">"  << y << " = " << (x >  y) << endl;
  cout << x << ">=" << y << " = " << (x >= y) << endl;


  return 0;
}
