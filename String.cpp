#include "String.h"



//DESTRUCTOR
String::~String()
{
  delete [] str;
}





//CONSTRUCTOR
String::String()
{
  str = new char[DEF_SIZE];

  str[0]='\0';
  size_ = 0;
  capacity_ = DEF_SIZE;
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

  if(size_ < DEF_SIZE)
  {
    capacity_ = DEF_SIZE;
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
  str = new char[DEF_SIZE];
  size_ = 0;
  capacity_ = DEF_SIZE;
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
String operator+(const String& lhs, const String& rhs)
{
  size_t sum = lhs.size_ + rhs.size_;
  //Update capacity if necessary
  String sum_s(lhs);


  //rhs.print_str_properties(999999);

  if(sum >= sum_s.capacity_)
  {
    sum_s.reserve(int(sum-lhs.capacity_));
  }

  //concatenate strings
  for (unsigned int i = sum_s.size_; i < sum ; ++i)
  {
    sum_s.str[i] = rhs.str[i-lhs.size_];
  }

  //Update size
  sum_s.size_ += rhs.size_;
  sum_s.str[sum_s.size_] = '\0';

  return sum_s;
}

String operator+(const String& lhs, char rhs)
{
  String sum_s(lhs);
  
  if(sum_s.size_+1 >= sum_s.capacity_)
  {
    sum_s.reserve(int(sum_s.size_-sum_s.capacity_) +1);
  }

  sum_s.str[sum_s.size_] = rhs;

  //Update size
  sum_s.size_ += 1;
  sum_s.str[sum_s.size_] = '\0';
  
  return sum_s;
}

//Operator+ by char*
String operator+(const String& lhs, const char* rhs) 
{
  String sum_s(lhs);
  
  //rhs size
  size_t s = 0;
  while(rhs[s] != '\0') {
      ++s;
  }
  //new size, prepared for copy
  size_t sum = sum_s.size_ + s;

  //check if capacity is big enough
  if (sum >= sum_s.capacity_) {
      sum_s.reserve(int(sum - sum_s.capacity_) +1);
  }

  //Copy of the char* = we add it to sum_s
  for (unsigned int i = sum_s.size_ ; i < sum; ++i) {
      sum_s.str[i] = rhs[i - sum_s.size_];
  }

  //Update size :
  sum_s.size_ = sum;

  //Add the '\0'
  sum_s.str[sum_s.size_] = '\0';

   return sum_s;

}

//Operator= by copy
String& String::operator=(const String& rhs)
{
  capacity_ = rhs.capacity_;
  size_ = rhs.capacity_;

  delete [] str;

  str = new char[capacity_];

  for(unsigned int i = 0; i < size_; ++i)
  {
    str[i] = rhs.str[i];
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

  if(size_ < DEF_SIZE)
  {
    capacity_ = DEF_SIZE;
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
  str = new char[DEF_SIZE];
  str[0] = c;
  str[1]='\0';
  size_ = 1;
  capacity_ = DEF_SIZE;
  return *this;
}
