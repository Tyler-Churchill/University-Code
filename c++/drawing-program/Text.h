
/// \author Howard Cheng Tyler Churchill
/// \date Sep 3, 2014
///
///
/// The Text class is an abstraction of a text string that can be 
/// drawn on a Screen.
///

#ifndef TEXT_H
#define TEXT_H

#include "ScreenElement.h"
#include <string>
#include <iostream>

using namespace std;

/// The Text class is an abstraction of a text string that can be
/// drawn on a Screen.  It is specified internally by the location of
/// the first character and the string itself.  It provides functions
/// to draw itself on a Screen as well as reading a description of
/// itself from an input stream.

class Text : virtual public ScreenElement {
protected:
  /// The row of the first character
  int m_row;
  
  /// The column of the first character
  int m_col;

  /// The text string
  string m_text;

public:
  /// constructs a text object
  ///
  /// \param[in] row the row of the first character
  /// \param[in] column the column of the first character
  /// \param[in] str the string
  Text(int row = 0, int column = 0, const string &str = "");

  /// draws the Text on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  virtual void draw(Screen &screen);

  /// reads a description of the Text from input stream.  The row and
  /// column of the first character, as well as the text string
  /// are specified on one line of input separated by spaces.
  //
  /// \throw input_format_error
  /// \param[in,out] is the input stream to read from
  virtual void read(istream &is);
};


#endif
