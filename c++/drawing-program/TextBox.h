
/// \author Howard Cheng with edits by Tyler Churchill
/// \date Sep 3, 2014
///
///
/// The TextBox class is an abstraction of a rectangular box containing
/// a text string that can be drawn on a Screen.
///

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Text.h"
#include "Box.h"

#include <iostream>
using namespace std;

/// The TextBox class is an abstraction of a rectangular box
/// containing a text string that can be drawn on a Screen.  It
/// provides functions to draw itself on a Screen as well as reading a
/// description of itself from an input stream.

class TextBox : public Text, public Box {
protected:

public:
  /// constructs a TextBox
  ///
  /// \param[in] row the row of the first character
  /// \param[in] column the column of the first character
  /// \param[in] ch the drawing character for the box
  /// \param[in] str the string
  TextBox(int row = 0, int column = 0, char ch = ' ', const string &str = "");

  /// draws the TextBox on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  virtual void draw(Screen &screen);

  /// reads a description of the TextBox from input stream.  The row
  /// and column of the first character, the drawing character of the
  /// box, as well as the string are specified on one line of input
  /// separated by spaces.
  //
  /// \throw input_format_error
  /// \param[in,out] is the input stream to read from
  virtual void read(istream &is);
};


#endif
