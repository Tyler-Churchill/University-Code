///
/// \date October 9 2014
/// \author Tyler Churchill
///

#pragma once

#include <stdexcept>

///
/// \brief An error which is thrown when the given coordinated are out of range
///
class invalid_coordinates_error : public std::runtime_error {
 
  public:
   /// \brief Constructs the invalid coordinate error
   ///
   /// Detailed description
   /// \param[in] description, the description of the error to be shown
  explicit invalid_coordinates_error(const std::string &description) : runtime_error(description) {}

};



///
/// \brief An error which is thrown when the given input does not meet the desired format
///
class input_format_error : public std::runtime_error {
 
  public:
   /// \brief Constructs the input format error
   ///
   /// Detailed description
   /// \param[in] description, the description of the error to be shown
   explicit input_format_error(const std::string &description) : std::runtime_error(description) {}

};


///
/// \brief An error which is thrown when a line is created that is not vertical or horizontal
///
class invalid_line_error : public std::runtime_error {
 
  public:
   /// \brief Constructs the invalid line error
   ///
   /// Detailed description
   /// \param[in] description, the description of the error to be shown
   explicit invalid_line_error(const std::string &description) : std::runtime_error(description) {}

};



///
/// \brief An error which is thrown when the user tried to add objects to the screen before the screen is created
///
class invalid_screen_error : public std::runtime_error {
 
  public:
   /// \brief Constructs the invalid screen error
   ///
   /// Detailed description
   /// \param[in] description, the description of the error to be shown
   explicit invalid_screen_error(const std::string &description) : std::runtime_error(description) {}

};

