
/// \author Howard Cheng with edits by Tyler Churchill
/// \date Sep 3, 2014
///
///
/// The Screen class is an abstraction of a 2D character array.
///

#include "Screen.h"
#include "Error.h"
#include <algorithm>

using namespace std;

// constructs a Screen object from the given dimensions
//
// \param[in] height the height of the array, default to 24
// \param[in] width the width of the array, default to 80
Screen::Screen(int height, int width)
   : m_height{height}, m_width{width}
{	
   m_array.assign(getRows(), std::vector<char>(getColumns(), ' '));
       
   clear();
}

// resets the entire array to spaces
void Screen::clear()
{
   m_array.assign(getRows(), std::vector<char>(getColumns(), ' '));
}

// sets the character at the given location to the given
// character.  The request is ignored if the location is invalid.
//
// \param[in] row row of the location
// \param[in] col column of the location
// \param[in] ch the character to put into the location
void Screen::set(int row, int col, char ch)
{
  if (0 <= row && row < m_height && 0 <= col && col < m_width) {
    m_array[row][col] = ch;
  } else {
     throw invalid_coordinates_error("Tried to set screen at invalid coordinates");
  }
};

// output the given Screen object to the output stream
//
// \param[in] os output stream
// \param[in] screen the Screen object
// \return the output stream
ostream &operator<<(ostream &os, const Screen &screen)
{
  for (int row = 0; row < screen.getRows(); row++) {
    for (int col = 0; col < screen.getColumns(); col++) {
      os << screen.m_array[row][col];
    }
    os << endl;
  }

  return os;
}


