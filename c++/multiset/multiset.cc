#include <assert.h>
#include "multiset.h"

size_t multiset::unique()
{
   return used;
}

const int& multiset::operator[](size_t i)
{
   assert(i >= 0 && i <= size() - 1);
   int n = i + 1;
   int pos;
   for(size_t x = 0; x < unique(); x++)
   {
      n -= dcount[x];
      if(n <= 0)
      {
	 pos = x;
	 break;
      }
   }
   return data[pos];
}

const int& multiset::operator()(size_t i)
{
   assert(0 <= i && i <= unique() - 1);
   return data[i];
}

size_t multiset::size()
{
   size_t sum = 0;
   for(size_t x = 0; x < unique(); x++)
   {
      sum += dcount[x];
   }
   return sum;
}

bool multiset::contains(const int &entry)
{
   for(size_t x = 0; x < unique(); x++)
   {
      if(entry == data[x])
      {
	 return true;
      }
   }
   return false;
}

void multiset::operator+=(multiset &m)
{
   for(size_t x = 0; x < m.unique(); x++)
   {
      // already contains
      if(contains(m(x)))
      {
	 dcount[pos(m(x))] += m.count(m(x));
      }
      // doesnt contain
      else
      {
	 insert(m(x), m.count(m(x)));
      }
   }
}

size_t multiset::count(const int &entry)
{
   size_t size = 0;
   if(contains(entry))
   {
      size = dcount[pos(entry)];
   }
   return size;
}

void multiset::insert(const int &entry, size_t num)
{
   int e = entry;
   // the entry does not exist
   if(!contains(e))
   {
      if(num != 0)
      {
	 data[used] = e;
	 dcount[used] = num;
	 used++;
      }
   }
   // the entry already exists
   else
   {
      dcount[pos(entry)] += num;    
   }
}

// doesnt return correct removed
size_t multiset::remove(const int &entry, size_t num)
{
   size_t removed = 0;
   if(!contains(entry))
   {
      return removed;
   } 
   // now contains
   else 
   {
      int attempt =  dcount[pos(entry)] - num;
      // removed all of number
      if(attempt <= 0)
      {
	 removed = dcount[pos(entry)];
	 for(size_t x = pos(entry); x < unique() - 1; x++)
	 {
	    data[x] = data[x + 1];
	    dcount[x] = dcount[x + 1];
	 }
	 used--;
      }
      // safe to remove num
      else
      {
	 dcount[pos(entry)] -= num;
	 removed += num;      
      } 
   }
   return removed;
}

size_t multiset::removeAll(const int &entry)
{
   if(contains(entry))
      return remove(entry, dcount[pos(entry)]);
   else
      return 0;
}

size_t multiset::pos(const int &entry)
{
   size_t pos = 0;
   for(size_t x = 0; x < used; x++)
   {
      if(entry == data[x])
      {
	 pos = x;
      }
   }
   return pos;
}

//-------------- NON-MEMBER -------------                                            

multiset operator+(multiset &m1, multiset &m2)
{
   multiset a(m1);
   multiset b(m2);
   a += b;
   return a;
}

bool operator==(const multiset &m1, const multiset &m2)
{
   multiset a(m1);
   multiset b(m2);
   if(a.size() != b.size())
      return false;
   for(size_t x = 0; x < a.unique(); x++)
   {
      if(a.count(a(x)) != b.count(a(x)))
	 return false;
   }
   return true;
}

std::ostream& operator<<(std::ostream &os, const multiset &m)
{
   multiset g(m);
   if(g.size() != 0)
   {
      os << "<";
      for(size_t x = 0; x < g.size(); x++)
      {
	 os << g[x];
	 if(x + 1 != g.size())
            os << ", ";
      }
      os << ">";
   }
   else
   {
      os << "< empty >";
   }
   return os;
}




