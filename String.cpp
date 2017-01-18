#include "String.h"



//DESTRUCTOR
String::~String()
{
  delete str;
  printf("\nTERMINATED\n");

}


  


//CONSTRUCTOR
String::String()
{
  str = new char(255);

  str[0]='\0';
  size_ = 0;
  capacity_ = 255;
}

String::String(const String &cp)
{
  str = new char(cp.capacity_);
  for (int i = 0; i < cp.size_; ++i) 
  {
    str[i] = cp.str[i];
  }

  size_ = cp.size_;
  capacity_ = cp.capacity_;

  str[size_]='\0';
}


String::String(char* c_string)
{
  int s = 0;
  while(c_string[s] != '\0')
  {
    ++s;
  }

  size_ = s;//sizeof(c_string); // Number of characters (without the '\0')

  if(size_ < 255)
  {
    capacity_ = 255;
  }
  else
  {
    capacity_ = size_ +1;
  }

  str = new char(capacity_);

  for(int i = 0; i < size_; ++i) // Don't copy the '\0' character
  {
    str[i] = c_string[i];
  }

}




//METHODS

char* String::c_str()
{
  //Returns the c-string.
  return str;
}



size_t String::size()
{
  // Returns the size of the string
  return size_;
}

size_t String::max_size()
{
  // Returns the maximum size a string can reach due to
  //the system or library implementations limitations
  return MAX_SIZE;
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




//Allow more size for the string
void String::reserve(int addedSize)
{
  //Init of new tab
  char* temp = str;
  int a = capacity_ + addedSize;
  str = new char(a);

  //Fill the new tab of the new string
  for (int i=0; i <= size_;i++)
    {
      str[i] = temp[i];
      printf("%c\n", temp[i] );
    }
  delete temp; 

  //Update capacity
  capacity_ += addedSize; 
}

String String::operator+(const String& left_s)
{
  String tmp_str(*this);

  //Update capacity if necessary
  if(tmp_str.size_ + left_s.size_ >= tmp_str.capacity_)
  {
    tmp_str.reserve((tmp_str.size_+left_s.size_)-tmp_str.capacity_);
  }
    
  //concatenate strings
  for (int i = tmp_str.size_; i < (left_s.size_+tmp_str.size_); ++i)
  {
    tmp_str.str[i] = left_s.str[i-tmp_str.size_];
  }
  
  //Update size
  tmp_str.size_  += left_s.size_;

  tmp_str.str[tmp_str.size_] = '\0';

  return tmp_str;
}
