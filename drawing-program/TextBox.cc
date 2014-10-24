
/// \author Howard Cheng with edits by Tyler Churchill
/// \date Sep 3, 2014
///
///
/// The TextBox class is an abstraction of a rectangular box containing
/// a text string that can be drawn on a Screen.
///

#include "TextBox.h"
#include "Error.h"
#include <string>

using namespace std;

// constructs a TextBox
//
// \param[in] row the row of the first character
// \param[in] column the column of the first character
// \param[in] ch the drawing character for the box
// \param[in] str the string
TextBox::TextBox(int row, int column, char ch, const string &str)
  : Text{row, column, str}, 
    Box{row-1, column-1, row+1, column+str.length(), ch}
{
}

// draws the TextBox on the given Screen
//
// \param[in,out] screen the screen to draw in
void TextBox::draw(Screen &screen)
{
  Text::draw(screen);
  Box::draw(screen);
}

// reads a description of the TextBox from input stream.  The row
// and column of the first character, the drawing character of the
// box, as well as the string are specified on one line of input
// separated by spaces.
//
// \param[in,out] is the input stream to read from
void TextBox::read(istream &is)
{
   char ch;
   string s;
   if(is >> m_row >> m_col >> ch >> m_text)
   {
      constructLines(m_row-1, m_col-1, m_row+1, m_col + m_text.length(), ch);

   } else {

      if(is >> s) {
	 throw input_format_error("Invalid input at TextBox::read() excess data");
      }
           cin.clear();
      while(cin.peek() != '\n')
	 cin.ignore(1);
     
   
     
      throw input_format_error("Invalid input for TextBox, try again");
   }


}

