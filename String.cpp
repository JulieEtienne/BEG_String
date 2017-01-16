#include "String.h"

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
