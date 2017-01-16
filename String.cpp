#include "String.h"


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
  size_ = str.length(c_string); // Number of characters
  if(size < 255)
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
