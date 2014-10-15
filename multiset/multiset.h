/**                                                                
 * CPSC2620 - Spring 2014 - Prof: Kevin                               
 * Assignment #2                                                         
 * File: multiset.h                                                             
 * Purpose: A container to store any int in any order                        
 * (Disregarding the order allowed for fast insertion and deletion)       
 *                                                                         
 * Written by: Tyler Churchill              
 * Date: Feb 6                                                             
 */

#ifndef MULTISET_H_
#define MULTISET_H_

#include <cstdlib>
#include <ostream>

const int MAX = 10000;

class multiset
{
  public:                                                                       
  multiset() : used(0) { }

   //------------------------- ACCESSORS------------------

   /**                                                                 
    * Function Name: operator[]                                            
    * Purpose: returns the ith element in your multiset.              
    */
   const int& operator[](size_t i);

   /**                                                                         
    * Function Name: operator()                                         
    * Purpose: returns the ith unique element in your multis                  
    */
   const int& operator()(size_t i);

   /**                                                      
    * Function Name: unique                                       
    * Purpose: returns the number of unique ints currently being
    *          stored in the multiset                 
    */
   size_t unique();

   /**                                                               
    * Function Name: size                                         
    * Purpose: returns the number of ints currently being stored in the multiset
    */
   size_t size();

   /**                                                             
    * Function Name: contains                                        
    * Purpose: contains returns true if the multiset contains a copy of entry
    *          and false otherwise                             
    */
   bool contains(const int &entry);

   /**
    * Function Name: count
    * Purpose: returns the number of ints in the multiset that match the entry
    */
   size_t count(const int &entry);

   //------------------------ MUTATORS-----------------------
                                                           
   /**
    * Function Name: insert                                                
    * Purpose: inserts an entry into your multiset.               
    *          The optional second parameter says how many copies you
    *          would like to insert.              
    *          note that if num is zero, then the function should not
    *          change anything                 
    */
   void insert(const int &entry, size_t num = 1);

   /**
    * Function Name: remove
    * Purpose: removes an entry from the multiset. The second parameter says how
    *          many copies to remove. Returns the number of elements
    *          actually removed.
    */
   size_t remove(const int &entry, size_t num = 1);

   /**
    * Function Name: removeAll
    * Purpose: removes an entry completely from the multiset. 
    */
   size_t removeAll(const int &entry);

   /**
    * Function Name: operator+=
    * Purpose: Adds the given multiset to the multiset
    */
   void operator+=(multiset &m);

  private:
   int data[MAX];
   size_t dcount[MAX];
   size_t used;
   /**
    * Function Name: pos
    * Purpose: returns position of entry inside the data array
    */
   size_t pos(const int &entry);
};

/**
 * Function Name: operator+
 * Purpose: adds m1 and m2 together
 */
multiset operator+(multiset &m1, multiset &m2);

/**
 * Function Name: operator==
 * Purpose: checks if m1 is equal to m2, returns false otherwise
 */
bool operator==(const multiset &m1, const multiset &m2);

/**
 * Function Name: operator<<
 * Purpose: outputs the multiset to the stream
 */
std::ostream& operator<<(std::ostream &os, const multiset &m);
#endif





