/**
 *  Author: Tyler Churchill
 *  SN: 001173045
 *  This map stores key/value pairs and grows to the size you need
 */

#ifndef MAP_H_
#define MAP_H_

#include <cstdlib>
#include <string>
#include <ostream>

typedef std::string Key;
typedef int Value;

struct entry {
   Key k;
   Value v;
};

class map {
  public:
   explicit map(size_t s = 3);
   map(const map &m);
   ~map();
   
   //******* ACCESSORS ********//

   /**
    * Function name: has
    * Purpose: Checks to see if the map contains the given key
    */
   bool has(const Key &k) const;
   /**
    * Function name: key
    * Purpose: Returns a key at the given position in the map
    */
   Key& key(size_t i) const;
   /**
    * Function name: value
    * Purpose: Returns a value at the given position in the map
    */
   Value& value(size_t i) const;
   /**
    * Function name: size
    * Purpose: Returns the size of the map
    */
   size_t size() const;
   /**
    * Function name: capacity
    * Purpose: Returns the maximum amount avaliabe to store keys/values
    */
   size_t capacity() const;
   /**
    * Function name: find
    * Purpose: Returns the value with the given key
    */
   const Value* find(const Key &k) const;

   //******* MUTATORS ********//

   /**
    * Function name: insert
    * Purpose: Inserts a new key/value pair into the map
    */
   void insert(const Key &k, const Value &v);
   /**
    * Function name: operator+=
    * Purpose: Adds values/keys of m to current map
    */
   map& operator=(const map &m);
    /**
    * Function name: operator+=
    * Purpose: Adds values/keys of m to current map
    */
   map& operator+=(const map &m);
   /**
    * Function name: find
    * Purpose: Returns a pointer to a value from the given key
    */
   Value* find(const Key &k);
   /**
    * Function name: reserve
    * Purpose: Allocates/reserves memory to the map
    */
   void reserve(size_t i);
   /**
    * Function name: clear
    * Purpose: Removes all key/value pairs in the map
    */
   void clear();
   /**
    * Function name: erase
    * Purpose: Removes the given key from the map
    */
   bool erase(const Key &k);
   
  private:
   /**
    * Function name: sort
    * Purpose: Sorts the map lexicographically
    */
   void sort();
   size_t max;
   size_t used;
   entry *entries;
};

//**** NON-MEMBER *****//

/**
 * Function name: operator<=
 * Purpose: Checks if m1 is a subset of m2
 */
bool operator<=(const map &m1, const map &m2);
/**
 * Function name: operator+
 * Purpose: Adds the key/value pairs of m2 to m1
 */
map operator+(const map &m1, const map &m2);
/**
 * Function name: operator<<
 * Purpose: Outputs the map to an ostream
 */
std::ostream& operator<<(std::ostream &os, const map &m);
/**
 * Function name: operator==
 * Purpose: Checks to see if m1 is equal to m2
 */
bool operator==(const map &m1, const map &m2);
#endif
