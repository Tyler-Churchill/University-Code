/**
 * Author: Tyler Churchill
 * SN: 001173045
 * This doubly linked list stores any given data type 
 */

#include <cassert>

/*******************************************
Const Iterator class for dlist
*******************************************/

// Constructor
template <typename Item>
dlist_const_iterator<Item>::dlist_const_iterator(const dnode<Item> *c)
{
   cur = c;
}

// MUTATORS

template <typename Item>
dlist_const_iterator<Item> dlist_const_iterator<Item>::operator++()
{
   cur = cur->next;
   return *this;
}

template <typename Item>
dlist_const_iterator<Item> dlist_const_iterator<Item>::operator++(int)
{
   dlist_const_iterator<Item> i(*this);
   ++(*this);
   return i;
}

template <typename Item>
dlist_const_iterator<Item> dlist_const_iterator<Item>::operator--()
{
   cur = cur->prev;
   return *this;
}

template <typename Item>
dlist_const_iterator<Item> dlist_const_iterator<Item>::operator--(int)
{
   dlist_const_iterator<Item> i(*this);
   --(*this);
   return i;
}

// ACCESSORS

template <typename Item>
const Item& dlist_const_iterator<Item>::operator*() const
{
   return cur->data;
}

template <typename Item>
bool dlist_const_iterator<Item>::operator==(const dlist_const_iterator &iter)const {
   return cur == iter.cur;
}

template <typename Item>
bool dlist_const_iterator<Item>::operator!=(const dlist_const_iterator &iter)const {
   return cur != iter.cur;
}


/*******************************************
dlist class.
*******************************************/

// Constructor

template <typename Item>
dlist<Item>::dlist()
{
   dummy = new dnode<Item>;
   dummy->next = dummy;
   dummy->prev = dummy;
   used = 0;
}

// Copy Constructor

template <typename Item>
dlist<Item>::dlist(const dlist &c)
{
   dummy = new dnode<Item>;
   dummy->next = dummy;
   dummy->prev = dummy;
   used = 0;
   
   std::cout<< "c.size() is: " << c.size() << std::endl;
   for(size_t x = 0; x < c.size(); x++)
   {
      // std::cout << "i is: " << i << std::endl;
      push_back(c[x]);
   }
      
}

// Destructor

template <typename Item>
dlist<Item>::~dlist()
{
   for(size_t x = 0; x < used; x++)
      pop_back();
}

// MUTATORS

template <typename Item>
dlist<Item>& dlist<Item>::operator=(const dlist &c)
{
   if(this == &c)
      return *this;

   for (size_t x = 0; x < used; x++)
      pop_back();

   for(size_t x = 0; x < c.size(); x++)
      insert(x, c.find(x)->data);
   
   used = c.size();
   
   return *this;
}


template <typename Item>
dlist<Item>& dlist<Item>::operator+=(const dlist &c)
{
   for(size_t x = 0; x < c.size(); x++)
      push_back(c[x]);

   return *this;
}


template <typename Item>
void dlist<Item>::push_back(const Item &value)
{
   insert(used, value);
}


template <typename Item>
void dlist<Item>::pop_back()
{
   erase(used - 1);
}

template <typename Item>
Item& dlist<Item>::operator[](size_t index)
{
   assert(index < used && index >= 0);
   return find(index)->data;
}

template <typename Item>
void dlist<Item>::insert(size_t i, const Item &value)
{
   if(i > used)
      i = used;
   
   if(used == 0)
   {
      dnode<Item> *a = new dnode<Item>(value,dummy,dummy);
      dummy->next = a;
      dummy->prev = a;
      
   }
   else
   {
      dnode<Item> *cursor = find(i);
      dnode<Item> *a = new dnode<Item>(value, cursor, cursor->prev);
      a->next->prev = a;
      a->prev->next = a;

   }
   used++;
}

template <typename Item>
dnode<Item>* dlist<Item>::find(size_t i)
{
   assert(i <= used);
   dnode<Item> *temp;
   if(i <= used/2)
   {
      temp = dummy->next;
      //next
      for(size_t x = 0; x < i ; x++)
	 temp = temp->next;
   }
   else
   {
      temp = dummy;

      //prev
      for(size_t x = i; x < used; x++)
	 temp = temp->prev;
   }
   return temp;
}

template <typename Item>
const dnode<Item>* dlist<Item>::find(size_t i) const
{
   assert(i <= used);
   dnode<Item> *temp;
   if(i <= used/2)
   {
      temp = dummy->next;
      //next
      for(size_t x = 0; x < i ; x++)
	 temp = temp->next;
   }
   else
   {
      temp = dummy;
      //prev
      for(size_t x = i; x < used; x++)
	 temp = temp->prev; 
      
   }
   return temp;
}

template <typename Item>
void dlist<Item>::erase(size_t i)
{
   assert(used >= 0);
    
   dnode<Item> *cursor = find(i);
   cursor->prev->next = cursor->next;
   cursor->next->prev = cursor->prev;

   used--;

   delete cursor;
}

template <typename Item>
Item& dlist<Item>::back()
{
   assert(used >= 0);
   return dummy->prev->data;
}

// ACCESSORS

template <typename Item>
size_t dlist<Item>::size() const
{
   return used;
}

template <typename Item>
const Item& dlist<Item>::operator[](size_t index) const
{
   assert(index < used);
   return find(index)->data;
}

template <typename Item>
const Item& dlist<Item>::back() const
{
   assert(used > 0);
   return dummy->prev->data;
}

template <typename Item>
dlist_const_iterator<Item> dlist<Item>::begin() const
{
   return dlist_const_iterator<Item>(dummy->next);
}

template <typename Item>
dlist_const_iterator<Item> dlist<Item>::end() const
{
   return dlist_const_iterator<Item>(dummy);
}


/*******************************************
Non-member functions for dlist and iterators
*******************************************/



template <class Item>
std::ostream& operator<<(std::ostream &os, const dlist<Item> &list)
{
   os << "<";
   dlist_const_iterator<Item> i = list.begin();
   while(i != list.end())
   {
      os << *i;
      i++;
      if(i != list.end())
	 os << ", ";
   }
   os << ">";
   return os;
}


template <class Item>
void print_reverse(const dlist<Item> &list)
{
   std::cout<< "<";
   dlist_const_iterator<Item> i = list.end();
   i--;
   while(i != list.begin())
   {
      std::cout << *i;
      i--;
      if(i != list.begin())
	 std::cout << ", ";
      else
	 std::cout <<", " <<  *i;
   }
   std::cout << ">";
}

template <class Item>
dlist<Item> reverse(const dlist<Item> &list)
{
   dlist_const_iterator<Item> i = list.end();
   i--;
   dlist<Item> a;
   for(size_t x = 0; x < list.size(); x++)
      a.push_back(*i--);

   return a;
}

template <class Item>
size_t count(const dlist<Item> &list, const Item &target)
{
   size_t total = 0;
   dlist_const_iterator<Item> i = list.begin();
   for(size_t x = 0; x < list.size(); x++)
      // if Item equals the target Item
      if(*i++ == target)
	 total++;
   return total;
}
