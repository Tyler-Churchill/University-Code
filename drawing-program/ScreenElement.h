
/// \author Howard Cheng with edits by Tyler Churchill
/// \date Sep 3, 2014
///
///
/// The ScreenElement class is an abstraction of any element that can
/// appear on a Screen.
///

#ifndef SCREENELEMENT_H
#define SCREENELEMENT_H

#include "Screen.h"
#include <iostream>
using namespace std;

/// The ScreenElement class is an abstraction of any element that can
/// appear on a Screen.  It provides functions to draw itself on a Screen
/// as well as reading a description of itself from an input stream.
class ScreenElement {

public:
  /// destroys the object
  virtual ~ScreenElement() { };

  /// draws the element on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  virtual void draw(Screen &screen) = 0;

  /// reads a description of the element from input stream
  //
  /// \param[in,out] is the input stream to read from
  virtual void read(istream &is) = 0;
};


#endif
