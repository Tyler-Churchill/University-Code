//
// CS 2720 Assignment 1 Solution
//
/// \author Howard Cheng
/// \date Sep 3, 2014
///
///
/// The Line class is an abstraction of a vertical or horizontal line that
/// can be drawn on a Screen.
///

#ifndef LINE_H
#define LINE_H

#include "ScreenElement.h"
#include <iostream>
using namespace std;

/// The Line class is an abstraction of a vertical or horizontal line
/// that can be drawn on a Screen.  It is specified internally by two
/// end points, as well as a character to draw the line with.  It
/// provides functions to draw itself on a Screen as well as reading a
/// description of itself from an input stream.

class Line : public ScreenElement {
protected:
  /// the row of the first end point
  int m_row1;
  
  /// the column of the first end point
  int m_col1;

  /// the row of the other end point
  int m_row2;
  
  /// the column of the other end point
  int m_col2;

  /// the drawing character
  char m_ch;

public:
  /// constructs a line
  ///
  /// \param[in] row1 the row of the first end point
  /// \param[in] column1 the column of the first end point
  /// \param[in] row2 the row of the second end point
  /// \param[in] column2 the column of the second end point
  /// \param[in] ch the drawing character
  Line(int row1 = 0, int column1 = 0, int row2 = 0, int column2 = 0, 
       char ch = ' ');

  /// draws the line on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  virtual void draw(Screen &screen);

  /// reads a description of the line from input stream.  The row and
  /// columns of the two end points, as well as the drawing character
  /// are specified on one line of input separated by spaces.
  //
  /// \throw input_format_error
  /// \param[in,out] is the input stream to read from
  virtual void read(istream &is);
};


#endif
