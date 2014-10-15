/**
 * Author: Tyler Churchill
 * SN: 001173045
 * This doubly linked list stores any given data type 
 */

#pragma once
#include <iostream>

/*******************************************
dnode struct.
*******************************************/

template <typename Item>
struct dnode {
	// Constructor
	dnode(const Item& d = Item(), dnode* n = nullptr, dnode* p = nullptr)
        {
	   data = d;
	   next = n;
	   prev = p;
	}

	// Variables
	Item data;
	dnode *next, *prev;
};


/*******************************************
Const Iterator class for dlist
*******************************************/

template <typename Item>
class dlist_const_iterator {
public:
	// Constructor
        explicit dlist_const_iterator(const dnode<Item> *c = nullptr);
	
	// Mutators

	/**
	 * Function Name: operator++
	 * Increases the iterator (postfix)
	 */
	dlist_const_iterator   operator++();
	
	/**
	 * Function Name: operator++
	 * Increases the iterator (prefix)
	 */
	dlist_const_iterator   operator++(int);
	
	/**
	 * Function Name: operator--
	 * Decreases the iterator (postfix)
	 */
	dlist_const_iterator   operator--();
	
	/**
	 * Function Name: operator--
	 * Decreases the iterator (prefix)
	 */
	dlist_const_iterator   operator--(int);

	// Accessors

	/**
	 * Function Name: operator*()
	 * Returns a dereferenced item
	 */
	const Item& operator*() const;
	
	/**
	 * Function Name: operator==
	 * Checks to see if the dnode's match
	 */
	bool operator==(const dlist_const_iterator &iter) const;
	
	/**
	 * Function Name: operator!=
	 * Checks to see if the dnode's do not match
	 */
	bool operator!=(const dlist_const_iterator &iter) const;

private:
	const dnode<Item> *cur;
};


/*******************************************
dlist class.
*******************************************/

template <typename Item>
class dlist {
public:

	// Constructors & Destructors
	dlist();
	dlist(const dlist &c);
	~dlist();

	// Mutator Methods

	/**
	 * Function Name: operator=
	 * Assigns the dlist to the current dlist
	 */
	dlist& operator=(const dlist &c);
	
	/**
	 * Function Name: operator+=
	 * Adds the given dlist to the dlist
	 */
	dlist& operator+=(const dlist &c);
	
	/**
	 * Function Name: push_back
	 * Inserts an Item to the end of the dlist
	 */
	void   push_back(const Item &value);

	/**
	 * Function Name: pop_back
	 * Removes the last Item from the dlist
	 */
	void   pop_back();

	/**
	 * Function Name: operator[]
	 * Returns the Item at the given index
	 */
	Item&  operator[](size_t index);

	/**
	 * Function Name: insert
	 * Inserts an item at the given index
	 */
	void   insert(size_t i, const Item &value);

	/**
	 * Function Name: erases
	 * Erases a node at the given index
	 */
	void   erase(size_t i);

	/**
	 * Function Name: back
	 * Returns a reference to the back item
	 */
	Item&  back();

	// Accessor Methods
	
	/**
	 * Function Name: size
	 * Returns the number of elements in the list
	 */
	size_t size() const;
       
	/**
	 * Function Name: operator[]
	 * Returns a reference to the item at the given index
	 */
	const Item& operator[](size_t index) const;
	
	/**
	 * Function Name: back
	 * Returns a const reference to the back item
	 */
	const Item& back() const;

	/**
	 * Function Name: begin
	 * Returns a iterator starting at the beginning of the list
	 */
	dlist_const_iterator<Item> begin() const;
	
	/**
	 * Function Name: end
	 * Returns a iterator starting at the end of the list
	 */
	dlist_const_iterator<Item> end()   const;



  private:
	
	/**
	 * Function Name: find
	 * Returns a pointer to the node at the given index
	 */
	dnode<Item>* find(size_t i);
	/**
	 * Function Name: find
	 * Returns a const pointer to the node at the given index
	 */
	const dnode<Item>* find(size_t i) const;

	dnode<Item> *dummy;
	size_t used;

};


/*******************************************
Non-member functions for dlist and iterators
*******************************************/

/**
 * Function Name: operator<<
 * Outputs the list to the output stream
 */
template <class Item>
std::ostream& operator<<(std::ostream &os, const dlist<Item> &list);

/**
 * Function Name: print_reverse
 * Outputs the list to the output stream
 */
template <class Item>
void print_reverse(const dlist<Item> &list);

/**
 * Function Name: operator<<
 * Outputs the list to the output stream
 */
template <class Item>
dlist<Item> reverse(const dlist<Item> &list);

/**
 * Function Name: operator<<
 * Outputes the list to the output stream
 */
template <class Item>
size_t count(const dlist<Item> &list, const Item &target);

#include "dlist.cc"
