#include "String.h"



//DESTRUCTOR
String::~String()
{
  delete [] str;
}


  


//CONSTRUCTOR
String::String()
{
  str = new char[255];

  str[0]='\0';
  size_ = 0;
  capacity_ = 255;
}

String::String(const String &cp)
{
  str = new char[cp.capacity_];
  for (unsigned int i = 0; i < cp.size_; ++i) 
  {
    str[i] = cp.str[i];
  }

  size_ = cp.size_;
  capacity_ = cp.capacity_;

  str[size_]='\0';
}


String::String(const char* c_string)
{
  int s = 0;
  while(c_string[s] != '\0')
  {
    ++s;
  }

  size_ = s; // Number of characters (without the '\0')

  if(size_ < 255)
  {
    capacity_ = 255;
  }
  else
  {
    capacity_ = size_ +1;
  }

  str = new char[capacity_];
  str[size_] = '\0';

  for(unsigned int i = 0; i < size_; ++i) // Don't copy the '\0' character
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
  //Returning the capacity
  return capacity_;
}



//Return True if array empty
bool String::empty()
{
  //Return True if array is empty
  return size_ == 0 ;
}




//Allow more size for the string
void String::reserve(int addedSize)
{
  int a = capacity_ + addedSize;

  //Init of new tab
  char* temp;
  
  temp = new char[a];

  //Fill the new tab of the new string
  for (unsigned int i=0; i <= size_;i++)
    {
      temp[i] = str[i];
    }
  delete [] str; 
  str = temp;

  //Update capacity
  capacity_ += addedSize; 
}

void String::resize(size_t n, char c)
{
    // resize an initial string to a new size n
    char* tmp = new char[n];

    if (n >= capacity_)
    {
      this->reserve(int(n-capacity_)+1);
    }

    for (unsigned int i = 0; i < n; i++) {
        if (i < size_) 
        {
          tmp[i] = str[i];
        } 
        else 
        {
          tmp[i] = c;
        }
    }
    size_ = n;
    tmp[size_] = '\0';

    delete [] str;
    str = tmp;
}

void String::clear()
{
  delete [] str;
  str = new char[255];
  size_ = 0;
  capacity_ = 255;
  str[0] = '\0';
}


void String::print_str_properties(int id)
{
  printf("\nString number %d properties\n", id);
  printf("\n Is empty:\t %s", this->empty()? "True":"False");

  printf("\n Capacity:\t %d", int(this->capacity()));
  printf("\n Size:\t\t %d", int(this->size()));
  printf("\n Content:\t %s\n-----------------\n", this->c_str());
}



//OPERATORS

//Operator+ by copy
String String::operator+(const String& left_s)
{
  String tmp_str(*this);

  //Update capacity if necessary
  if(tmp_str.size_ + left_s.size_ >= tmp_str.capacity_)
  {
    tmp_str.reserve(int((tmp_str.size_+left_s.size_)-tmp_str.capacity_));
  }
    
  //concatenate strings
  for (unsigned int i = tmp_str.size_; i < (left_s.size_+tmp_str.size_); ++i)
  {
    tmp_str.str[i] = left_s.str[i-tmp_str.size_];
  }
  
  //Update size
  printf("\nMOUAHA : %d\n", int(left_s.size_));
  tmp_str.size_  += left_s.size_;

  tmp_str.str[tmp_str.size_] = '\0';

  return tmp_str;
}

//Operator= by copy
String& String::operator=(const String& left_s)
{
  capacity_ = left_s.capacity_;
  size_ = left_s.capacity_;

  delete [] str;  

  str = new char[capacity_];

  for(unsigned int i = 0; i < size_; ++i)
  {
    str[i] = left_s.str[i];
  }

  return *this;
}

//Operator= by c_str
String& String::operator=(const char* c_string)
{
  int s = 0;
  while(c_string[s] != '\0')
  {
    ++s;
  }

  size_ = s; // Number of characters (without the '\0')

  if(size_ < 255)
  {
    capacity_ = 255;
  }
  else
  {
    capacity_ = size_ +1;
  }

  str = new char[capacity_];
  str[size_] = '\0';

  for(unsigned int i = 0; i < size_; ++i) 
  {
    str[i] = c_string[i];
  }
  return *this;
}

//Operator= by char
String& String::operator=(char c)
{
  str = new char[255];
  str[0] = c;
  str[1]='\0';
  size_ = 1;
  capacity_ = 255;
  return *this;
}