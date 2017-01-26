#include "String.h"


// CONSTRUCTORS

String::String()
{
  //Default constructor

  str = new char[255];

  str[0]='\0';
  size_ = 0;
  capacity_ = 255;
}


String::String(const String &cp)
{
  //Copy constructor

  str = new char[cp.capacity_];
  //Copies the value of cp in str
  for (unsigned int i = 0; i < cp.size_; ++i)
  {
    str[i] = cp.str[i];
  }

  size_ = cp.size_;
  capacity_ = cp.capacity_;

  //Adds the '\0' at the end to close the String
  str[size_]='\0';
}


String::String(const char* c_string)
{
  //C-string constructor

  int s = 0;
  //Gets the size of c_string
  while(c_string[s] != '\0')
  {
    ++s;
  }

  //Number of characters (without the '\0')
  size_ = s;

  /**Determines if the String fits in the default capacity,
     Otherwise, sets the capacity to size_+1 or to the maximum
     required depending on the size_**/
  if (size_ >= MAX_SIZE)
  {
    capacity_ = MAX_SIZE;
  }
  else
  {
    capacity_ = size_ > 255 ? size_+1 : 255;
  }

  str = new char[capacity_];
  str[size_] = '\0';

  //Copies the value of c-string and doesn't copy the '\0' character
  for (unsigned int i = 0; i < size_; ++i)
  {
    str[i] = c_string[i];
  }
}


// DESTRUCTOR

String::~String()
{
  //Deletes the char*

  delete [] str;
}


// MEMBER FUNCTIONS

char* String::c_str()
{
  //Returns the c-string

  return str;
}


size_t String::size()
{
  // Returns the size of the String

  return size_;
}


size_t String::max_size()
{
  /**Returns the maximum size a string can reach due to
  the system or library implementations limitations**/

  return MAX_SIZE;
}


size_t String::length()
{
    //Returns the size of the String

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


void String::reserve(int addedSize)
{
  //Allows more size for the String

  int a = capacity_ + addedSize;

  //Initializes of new tab
  char* temp;
  temp = new char[a];

  //Fills the new tab with the new String
  for (unsigned int i=0; i <= size_;i++)
    {
      temp[i] = str[i];
    }
  delete [] str;
  str = temp;

  //Updates capacity
  capacity_ += addedSize;
}


void String::resize(size_t n, char c)
{
    /**Resizes an initial String to a new size n :
       If n > size : adds blank boxes or fills them with c
       If n < size : truncates the String **/

    //Creates a temporary table
    char* tmp = new char[n];

    /**If size if greater than capacity,
       we need to allow more boxes **/
    if (n >= capacity_)
    {
      this->reserve(int(n-capacity_)+1);
    }

    //Copies the value of the string in tmp
    //Replaces blank space by char c if needed and asked
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
  //Empties the String
  delete [] str;
  str = new char[255];
  size_ = 0;
  capacity_ = 255;
  str[0] = '\0';
}


void String::print_str_properties(int id)
{
  //Easier way to view results while testing
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

  //Reset the tabular str
  delete [] str;

  //Allow the new capacity
  str = new char[capacity_];

  //Fill the new char tabular
  for(unsigned int i = 0; i < size_; ++i)
  {
    str[i] = rhs.str[i];
  }

  return *this;
}


//Operator= by c_str
String& String::operator=(const char* c_string)
{
  //Put in "s" the size of c_string
  int s = 0;
  while(c_string[s] != '\0')
  {
    ++s;
  }

  // Number of characters (without the '\0')
  size_ = s;

  if(size_ < 255)
  {
    capacity_ = 255;
  }
  else
  {
    capacity_ = size_ +1;
  }

  //creation of the char tabular ended with '\0'
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
  //Creation of the new char tabular with the default capacity
  str = new char[255];

  //Added the char end the and '\0'
  str[0] = c;
  str[1]='\0';
  size_ = 1;
  capacity_ = 255;
  return *this;
}
