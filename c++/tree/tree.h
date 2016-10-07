/**
 * Author: Tyler Churchill
 * SN: 001173045
 * This n-ary tree stores any given data type
 */

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include <iostream>

/*******************************************
 Tree node structure.
 *******************************************/

template <typename Item>
struct tree_node {
  Item data;
  std::vector<tree_node*> children;
  tree_node(const Item &d = Item()) : data(d) {}
};

/*******************************************
 Tree node toolkit.
 *******************************************/

//*******************************************************************
// Function Name: tree_size
// Purpose: Takes a tree node pointer as input, and returns the 
//          number of treenodes below and including that treenode
//*******************************************************************
template <typename Item>
size_t tree_size( const tree_node<Item> *head );

//*******************************************************************
// Function Name: tree_copy
// Purpose: Takes two tree node pointers as input. The first pointer
//          points to the root of the tree to be copied. The second
//          pointer is a pointer to the new copy of the tree
//*******************************************************************
template <typename Item>
void tree_copy(const tree_node<Item>* source, tree_node<Item>*& head);

//*******************************************************************
// Function Name: tree_clear
// Purpose: Takes a tree node pointer as input, and deletes all
//          treenodes below and including that treenode
//*******************************************************************
template <typename Item> 
void tree_clear(tree_node<Item>*& head);

//*******************************************************************
// Function Name: tree_search
// Purpose: Takes in a item to search for and a head. Preforms a preorder
//          search returning a pointer to the node containing the target
//          if it exists, otherwise returns nullptr
//*******************************************************************
template <typename Item> 
tree_node<Item>* tree_search(tree_node<Item>* head, const Item& target);

//*******************************************************************
// Function Name: tree_height
// Purpose: Returns the longest path of the tree
//*******************************************************************
template <typename Item>
size_t tree_height(const tree_node<Item> *head);


template <typename Item>
class Tree
{
  public:
   // constructor
   explicit Tree( const Item &d = Item());
   // copy constructor
   Tree(const Tree &t);
   // deconstructor
  ~Tree();

  // Mutators

  //*******************************************************************
  // Function Name: operator=
  // Purpose: Assigns the current tree to the given tree
  //*******************************************************************
  Tree& operator=(const Tree &t);

  //*******************************************************************
  // Function Name: insert
  // Purpose: Inserts a given entry onto the given parent
  //*******************************************************************
  bool insert(const Item &entry, const Item &parent);

  //*******************************************************************
  // Function Name: remove
  // Purpose: Removes a given entry from the current tree
  //*******************************************************************
  bool remove(const Item &entry);

  // Accessors

  //*******************************************************************
  // Function Name: size
  // Purpose: Returns the number of nodes in the tree
  //*******************************************************************
  size_t size() const;

  //*******************************************************************
  // Function Name: height
  // Purpose: Returns the length of the longest path in the tree
  //*******************************************************************
  size_t height() const;

  //*******************************************************************
  // Function Name: contains
  // Purpose: Returns true if the tree contains the given entry 
  //*******************************************************************
  bool contains(const Item &entry) const;

  //*******************************************************************
  // Function Name: descendants
  // Purpose: Puts the descendants of the given entry into the given
  //          vector
  //*******************************************************************
  bool descendants(const Item &entry, std::vector<Item> &v) const;

  //*******************************************************************
  // Function Name: print
  // Purpose: Prints out the tree in preorder
  //*******************************************************************
  void print() const;

private:
  tree_node<Item> *root;
};

// Non member

//*******************************************************************
// Function Name: print_preorder
// Purpose: Prints out the tree in preorder
//*******************************************************************
template <typename Item>
void print_preorder(tree_node<Item>* node);

//*******************************************************************
// Function Name: tree_height
// Purpose: Returns a pointer to the parent node of the given node
//*******************************************************************
template <typename Item>
tree_node<Item>* find_parent(tree_node<Item>* node, const Item& d);

#include "tree.cc"
#endif
