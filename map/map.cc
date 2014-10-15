#include "map.h"
#include <cassert>

/**
 * initializes (constructs) a new map of max 3
 */
map::map(size_t s)
{
   used = 0;
   max = s;
   entries = new entry[max];
}

/**
 * copies the given map to the current one
 */
map::map(const map &m)
{
   max = m.capacity();
   used = m.size();
   entries = new entry[max];
   for(size_t x = 0; x < used; x++)
   {
      entries[x] = m.entries[x];
   }
}

/**
 * assigns the given map to the current one
 */
map& map::operator=(const map &m)
{
   if(!(*this == m))
   {  
      delete [] entries;
      entries = new entry[m.capacity()];
      used = m.size();
      max = m.capacity();
      for(size_t x = 0; x < used; x++)
	 entries[x] = m.entries[x];
   }
   return *this;
}

/**
 * This adds the key/value pair <k,v> into the map
 */
void map::insert(const Key &k, const Value &v)
{
   if(has(k))
   {
      *find(k) = v;
   }
   else {
      if(used == max)
	 reserve(static_cast<int>(max * 1.5 + 1));
      
      entries[used].k = k;
      entries[used].v = v;
      used++;

      if(used != 0)
      sort();
   }
}

/**
 * Returns a pointer constant 
 * to the value being stored that is associated with key k
 */
const Value* map::find(const Key &k) const
{
   if(has(k))
   {
      for(size_t x = 0; x < used; x++)
      {
	 if(entries[x].k == k)
	 {
	    return &entries[x].v;
	 }
      }
   }
   return nullptr;
}
						
/**						
 * Returns a pointer to the value being stored that is associated with key k
 */
Value* map::find(const Key &k)
{
   if(has(k))
   {
      for(size_t x = 0; x < used; x++)
      {
	 if(entries[x].k == k)
	 {
	    return &entries[x].v;
	 }
      }
   }
   return nullptr;
}

/**
 * Returns true if there is an element being stored that has key k,
 * and false otherwise
 */
bool map::has(const Key &k) const
{
   for(size_t x = 0; x < size(); x++)
   {
      if(entries[x].k == k)
	 return true;
   }
   return false;
}

/**
 * returns the current size of the map
 */
size_t map::size() const
{
   return used;
}

/**
 * returns the current allocated max amount of entries
 */
size_t map::capacity() const
{
   return max;
}

/**
 * frees up maps resources
 */
map::~map()
{
   delete [] entries;
}			  

/**
 * returns a reference to the key at the given positon in the map
 */
Key& map::key(size_t i) const
{
   assert(i < used);
   return entries[i].k;
}

/**
 * retuns a reference to the value at the given position in the map
 */
Value& map::value(size_t i) const
{
   return entries[i].v;
}

/**
 * resrves new memory space as the map grows in size
 */ 
void map::reserve(size_t i)
{
   if(i < used)
      used = i;
   
   entry *temp = new entry[i];
   for(size_t x = 0; x < used; x++)
      temp[x] = entries[x];
   delete [] entries;
   entries = temp;
   max = i;
}

/**
 * clears all key/value pairs from the map
 */
void map::clear()
{
   delete [] entries;
   entries = new entry[max];
   used = 0;
}

/**
 * Removes the value associated with key k. Return true if a value was removed,
 *  false otherwise (in the case that there was no value with that key to begin with)
 */
bool map::erase(const Key &k)
{
   if(has(k))
   {
      size_t pos;
      for(size_t x = 0; x < used; x++)
      {
	 if(entries[x].k == k)
	    pos = x;
      }
      for(size_t i = pos; i < used - 1; i++)
      {
	 entries[i] = entries[i + 1];
      }
      used--;
      return true;
   }

   return false;
}

/**
 * adds the key/value pairs from m to the current map
 */
map& map::operator+=(const map &m)
{
   if(m.size() == 0)
      return *this;

   for(size_t x = 0; x < m.used; x++)
   {
      insert(m.entries[x].k, m.entries[x].v);
   }
   return *this;
}

/**
 * sorts the map lexicographically (VERY INEFFICIENT)
 */
void map::sort()
{
   entry temp;
   for(size_t x = 1; x < used; x++)
   {
      for(size_t y = 0; y < used - 1; y++)
      {
	 if(entries[y].k > entries[y + 1].k)
	 {
	    temp = entries[y];
	    entries[y] = entries[y + 1];
	    entries[y + 1] = temp;
	 }
      }
   }
}

/******* NON MEMBER ******/

/**
 * return true if m1 is a subset of m2 or m1 is equal to m2
 */
bool operator<=(const map &m1, const map &m2)
{
   for(size_t x = 0; x < m1.size(); x++)
   {
      if(m2.has(m1.key(x)))
      {
	   if(*m2.find(m1.key(x)) != m1.value(x))
	       return false;
      }
      else
	     return false;
   }
   return true;
}

/**
 * adds m1 to m2
 */
map operator+(const map &m1, const map &m2)
{
   map a(m1);
   a += m2;
   return a;
}

/**
 * returns true if m1 and m2 are equal, false otherwise
 */
bool operator==(const map &m1, const map &m2)
{
   if(m1.size() != m2.size())
   {
      return false;
   }
   for(size_t x = 0; x < m1.size(); x++)
   {
      if(m1.key(x) != m2.key(x))
	 return false;
      if(m1.value(x) != m2.value(x))
	 return false;
   }
   return true;
}

/**
 * prints out the map to the ostream
 */
std::ostream& operator<<(std::ostream &os, const map &m)
{
   os << "{";
   for(size_t x = 0; x < m.size(); x++)
   {
      os << "<" << m.key(x) << ": " << m.value(x) << ">";
      if(x + 1 != m.size())
	 os << ", ";
   }
   os << "}";
   
   return os;
}
