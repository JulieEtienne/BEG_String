#include "String.h"






//CONSTRUCTOR
String::String()
{
  str = new char(255);

  size_ = 0;
  capacity_ = 255;
}