/**
 * Author: Tyler Churchill
 *
 * Creates an arithmetical integer data type
 */

#include <assert.h>
#include "integer.h"

Integer::Integer(const unsigned int &value)
{
   clear();
   digits = 0;
   int accum = value;
   while(accum > 0)
   {
      array[digits] = accum % 10;
      accum /= 10;
      digits++;
   }
}

Integer::Integer(const string &value)
{
   clear();
   digits = value.size();
   string in = value;
   for(size_t i = 0; i < digits; i++)
      array[i] = static_cast<unsigned short>(in[digits - 1 - i]) - 48;
}

// Returns the ith digit of the number
short Integer::operator[](const size_t &i)
{
   assert(i < 30);
   return array[i];
}

// Adds value to current integer
void Integer::operator+=(const Integer &v)
{
   Integer temp = v;
   int carry = 0;
   for(int x = 0; x < SIZE; x++)
   {
      array[x] += temp[x] + carry;
      carry = 0;
      if(array[x] > 9)
      {
	 array[x] -= 10;
	 carry++;
      }
   }

   calcSize();
}

// Add a value of 1 to the integer (prefix)
Integer Integer::operator++()
{
   Integer temp = *this;
   Integer add(1);
   temp += add;
   *this = temp;
   return temp;
}

// Add a value of 1 to the integer (postfix)
Integer Integer::operator++(int)
{
   Integer temp = *this;
   Integer before = *this;
   Integer add(1);
   temp += add;
   *this = temp;
   return before;
}

// Shift left by i digits
void Integer::operator<<=(const size_t &i)
{
   Integer temp = (*this);
   for(int x = 0; x < SIZE; x++)
   {
      if(x + i < 30)
	 array[x + i] = temp[x];
   }

   for(unsigned int x = 0; x < i; x++)
   {
      array[x] = 0;
      digits += i;
   }
   calcSize();
}

// Shift right by i digits
void Integer::operator>>=(const size_t &i)
{
   Integer temp = *this;
   clear();
   for(int x = 0; x < SIZE; x++)
   {
      if(x + i < 30)
	 array[x] = temp[x + i];

   }  
   calcSize();
}

// Returns the number of digits the number has
size_t Integer::size()
{
   return digits;
}

// Sets every number of the integer to 0
void Integer::clear()
{
   for(int x = 0; x < SIZE; x++)
      array[x] = 0;
   digits = 0;
}

void Integer::calcSize()
{
   digits = SIZE;
   for(int i = SIZE - 1; i >= 0; i--)
   {
      if(array[i] != 0) break;
      digits--;
   }
   
}

//---------------------- NON MEMBER FUNCTIONS -------------------------//

// Returns an integer that is an addition of v1 and v2
Integer operator+(const Integer &v1, const Integer &v2)
{
   Integer a(v1);
   Integer b(v2);
   Integer r = a;
   r += b;
   return r;
}

// Returns an Integer that is the v shifted to the left by i digits
Integer operator<<(const Integer &v, const size_t &i)
{
   Integer temp = v;
   temp <<= i;
   return temp;
}

// Returns an Integer that is the v shifted to the right by i digits
Integer operator>>(const Integer &v, const size_t &i)
{
   Integer temp = v;
   temp >>= i;
   return temp;
}

// Returns true if v1 and v2 are equal
bool operator==(const Integer &v1, const Integer &v2)
{
   Integer a(v1);
   Integer b(v2);

   for(unsigned int x = 0; x < a.size() ; x++)
   {
      if(a[x] != b[x])
	 return false;
   }
   return true;
}

// Returns true if v1 and v2 are not equal
bool operator!=(const Integer &v1, const Integer &v2)
{
   Integer a(v1);
   Integer b(v2);
   if(a == b)
      return false;
   return true;
}

// Returns true if v1's value is less than v2's value
bool operator<(const Integer &v1, const Integer &v2)
{
   Integer less = v1;
   Integer more = v2;
   if(less.size() < more.size())
      return true;
   for(int x = less.size() - 1; x >= 0; x--)
   {
      if(less[x] < more[x])
	 return true;
   }
   return false;
}

// Returns true if v1's value is less than or equal to v2's value
bool operator<=(const Integer &v1, const Integer &v2)
{
   if(v1 < v2 || v1 == v2)
      return true;
   return false;
}

// Returns true if v1's value is greater than v2's value
bool operator>(const Integer &v1, const Integer &v2)
{
   return !(v1 <= v2);
}

// Returns true if v1's value is greater than or equal to v2's value
bool operator>=(const Integer &v1, const Integer &v2)
{
   if(v1 > v2 || v1 == v2)
      return true;
   return false;
}

// Prints the integer to the screen
ostream& operator<<(ostream &os, const Integer &v)
{
   Integer temp = v;
   for(int i = temp.size() - 1; i >= 0; i--)
      os << temp[i];
   return os;
}

// Reads an integer from input stream
istream& operator>>(istream &os, Integer &v)
{
   int temp = 0;
   os >> temp;
   Integer i(temp);
   v = i;
   return os;
}
