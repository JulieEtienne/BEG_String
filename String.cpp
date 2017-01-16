#include "String.h"



//Destructor
String::~String()
{
// Empty
}

//Returning the size_t capacity
int String::capacity()
{
  return capacity_;
}

//Return True if array empty
bool String::empty()
{

  if (size_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//CONSTRUCTOR
String::String()
{
  str = new char(255);

  size_ = 0;
  capacity_ = 255;
}

String::String(const String &cp)
{
  str = new char(*(cp.str));

  size_ = cp.size_;
  capacity_ = cp.capacity_;
}


String::String(char* c_string)
{
  size_ = sizeof(c_string) - 1; // Number of characters
  if(size_ < 255)
  {
      capacity_ = 255;
  } else {
      capacity_ = size_;
  }
  str = new char(capacity_);
  for(int i = 0; i<size_-1; ++i) // Don't copy the '\0' character
  {
    str[i] = c_string[i];
  }
}


size_t String::size()
{
  // Returns the size of the array
  return size_;
}


size_t String::max_size()
{
  // Returns the maximum size a string can reach due to
  //the system or library implementations limitations
  return MAX_SIZE;
}
