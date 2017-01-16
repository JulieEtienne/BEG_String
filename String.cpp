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