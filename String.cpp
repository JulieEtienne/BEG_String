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


String::String(const char* c_string)
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

  for(unsigned int i = 0; i < size_; ++i) // Don't copy the '\0' character
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


size_t String::capacity()
{
  //Returning the capacity
  return capacity_;
}


bool String::empty()
{
  //Return True if array is empty
  return size_ == 0 ;
}


//Allow more size for the string
void String::reserve(size_t addedSize)
{
  //Init of new tab
  char* temp = new char(capacity_ + addedSize);

  //Fill the new tab of the new string
  for (unsigned int i=0; i<size_;i++)
    {
      temp[i] = str[i];
    }

  delete str; //Delete old string
  str = temp; //Recreate the string
}

void String::resize(size_t n, char c)
{
    // resize an initial string to a new size n
    char* tmp = NULL;

    //Allocate memory to tmp var
    //If malloc returns, means it didn't work
    if (!(tmp = (char *)malloc(sizeof(char) * n)))
        return ;
    for (unsigned int i = 0; i < n; i++) {
        //if this->str exists => n > this->size_
        if (this->str[i]) {
            tmp[i] = this->str[i];
        } else {
            tmp[i] = c;
        }
    }
    //Same ptrs
    delete this->str;
    this->str = tmp;
}
