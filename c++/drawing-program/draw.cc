
/// \author Howard Cheng with edits Tyler Churchill
/// \date Sep 3, 2014
///
///
/// This is a program that allows the user to draw a number of boxes, text
/// strings, and text boxes (strings surrounded by a box) on a screen.
///

#include <iostream>
#include <vector>
#include <cassert>
#include "Error.h"
#include "Screen.h"
#include "ScreenElement.h"
#include "Line.h"
#include "Box.h"
#include "Text.h"
#include "TextBox.h"

using namespace std;

/// print a menu of commands
void printMenu(void);

/// remove all screen elements that are in the system
///
/// \param[in] vec the vector of ScreenElement pointers
void clearVector(vector<ScreenElement *> &vec);

/// determine if a screen has been created.  Produce an error message if not.
///
/// \param[in] screen_ptr a pointer to the Screen object, or NULL if it has not been created yet.
/// \return whether the screen has been created.           
bool checkScreenReady(Screen *screen_ptr);

/// insert a ScreenElement into the system and draw it on screen
///
/// \param[in] screen the Screen object
/// \param[in] vec the vector of ScreenElement pointers
/// \param[in] element a pointer to the ScreenElement to be added
void insertElement(Screen &screen, vector<ScreenElement *> &vec, 
		   ScreenElement *element);

/// redraw the entire screen from scratch based on the given list of ScreenElements
///
/// \param[in] screen the Screen object
/// \param[in] vec the vector of ScreenElement pointers
void redraw(Screen &screen, const vector<ScreenElement *> &vec);


int main(void)
{
  Screen *screen = NULL;
  vector<ScreenElement *> vec;
  char ch;

  while (1) {

     try {
     
    printMenu();
    cin >> ch;
    // eat white space
    while (cin.peek() != '\n') {
      cin.ignore();
    }
    cin.ignore();

    switch(ch) {
       case 'N': case 'n':
	  delete screen;
	  screen = new Screen;
	  clearVector(vec);
	  break;
       case 'B': case 'b':
	  if (checkScreenReady(screen)) {
	   
	     Box *box = new Box;
	     insertElement(*screen, vec, box);		
	  
	  }
	  break;
       case 'T': case 't':
	  if (checkScreenReady(screen)) {
	     Text *text = new Text;
	     insertElement(*screen, vec, text);
      }
      break;
    case 'R': case 'r':
      if (checkScreenReady(screen)) {
	TextBox *textbox = new TextBox;
	insertElement(*screen, vec, textbox);
      }
      break;
    case 'D': case 'd':
      if (checkScreenReady(screen)) {
	cout << *screen << endl;
      }
      break;
    case 'K': case 'k':
      if (vec.size() == 0) {
	cerr << "Nothing to remove" << endl;
      } else {
	// if vector has size > 0 then the screen must be ready, better
	// still check just in case
	 checkScreenReady(screen);
	delete vec[vec.size()-1];
	vec.pop_back();
	redraw(*screen, vec);
      }
      break;
    case 'Q': case 'q':
      delete screen;
      clearVector(vec);
      return 0;
    }

     } catch (invalid_screen_error e) {
	cout << endl << e.what() << endl;
     }
    
  }
  
  
  return 0;
}

// print a menu of commands
void printMenu(void)
{
  cout << endl;
  cout << "          Menu         " << endl << endl;
  cout << "N: creates a new screen" << endl;
  cout << "B: creates a Box object" << endl;
  cout << "T: creates a Text object" << endl;
  cout << "R: creates a TextBox object" << endl;
  cout << "D: draws the screen" << endl;
  cout << "K: removes most recently added ScreenElement" << endl;
  cout << "Q: quit the program" << endl;
  cout << endl;
  cout << "> ";
}

// remove all screen elements that are in the system
//
// \param[in] vec the vector of ScreenElement pointers
void clearVector(vector<ScreenElement *> &vec)
{
  for (unsigned int i = 0; i < vec.size(); i++) {
    delete vec[i];
  }
  vec.clear();
}

// determine if a screen has been created.  Produce an error message if not.
//
// \param[in] screen_ptr a pointer to the Screen object, or NULL if it has not been created yet.
// \return whether the screen has been created.           
bool checkScreenReady(Screen *screen_ptr)
{
  if (screen_ptr == NULL) {
     throw invalid_screen_error("Tried to make screen element or display screen while the screen hasn't been created");
  } else {
    return true;
  }
}

// insert a ScreenElement into the system and draw it on screen
//
// \param[in] screen the Screen object
// \param[in] vec the vector of ScreenElement pointers
// \param[in] element a pointer to the ScreenElement to be added
void insertElement(Screen &screen, vector<ScreenElement *> &vec,  ScreenElement *element)
{
   bool d;

   do {
      d = false;
      try {
	
	 element->read(cin);
	
      } catch (input_format_error e) {
	 cout << e.what() << endl;
	 d = true;
      }

   
   } while(d);
	 
   try {
      vec.push_back(element);
  
      element->draw(screen);
   }catch (invalid_coordinates_error e)
   {
      delete vec[vec.size()-1];
      vec.pop_back();
      redraw(screen, vec);
      cout << e.what() << endl;
   }
}

// redraw the entire screen from scratch based on the given list of ScreenElements
//
// \param[in] screen the Screen object
// \param[in] vec the vector of ScreenElement pointers
void redraw(Screen &screen, const vector<ScreenElement *> &vec)
{

   screen.clear();
   for (const auto &v : vec) {
      v->draw(screen);
   }
  
}
