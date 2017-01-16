#include "String.h"



//DESTRUCTOR
String::~String()
{
// Empty
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
  size_ = sizeof(c_string) - 2; // Number of characters

  if(size_ < 255)
  {
      capacity_ = 255;
  } 
  else 
  {
      capacity_ = size_;
  }

  str = new char(capacity_);

  for(int i = 0; i<size_; ++i) // Don't copy the '\0' character
  {
    str[i] = c_string[i];
  }
}


//METHODS

char* String::c_str()
{
  return str;
}


size_t String::size()
{
  return size_;
}

size_t String::length()
{
  return size_;
}

//Returning the size_t capacity
size_t String::capacity()
{
  return capacity_;
}

//Return True if array empty
bool String::empty()
{
  return size_ == 0 ;
}
