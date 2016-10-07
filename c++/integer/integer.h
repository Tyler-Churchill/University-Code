#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>

using namespace std;

const int SIZE = 30;

class Integer
{
  public:
   Integer(const unsigned int &value = 0);
   Integer(const string &str);
   // Add a value of 1 to the integer (prefix)
   Integer operator++();
   // Add a value of 1 to the integer (postfix)
   Integer operator++(int);
   // Returns the ith digit of the number
   short operator[](const size_t &i);
   // Adds value to current integer
   void operator+=(const Integer &v);
   // Shift left by i digits
   void operator<<=(const size_t &i);
   // Shift right by i digits
   void operator>>=(const size_t &i);
   // Returns how many digits the number has
   size_t size();
  private:
   short array[SIZE];
   unsigned int digits;
   void clear();
   void calcSize();
};

Integer operator+(const Integer &v1, const Integer &v2);
Integer operator<<(const Integer &v, const size_t &i);
Integer operator>>(const Integer &v, const size_t &i);
bool operator==(const Integer &v1, const Integer &v2);
bool operator!=(const Integer &v1, const Integer &v2);
bool operator<(const Integer &v1, const Integer &v2);
bool operator<=(const Integer &v1, const Integer &v2);
bool operator>(const Integer &v1, const Integer &v2);
bool operator>=(const Integer &v1, const Integer &v2);
ostream& operator<<(ostream &os, const Integer &v);
istream& operator>>(istream &os, Integer &v);

#endif
