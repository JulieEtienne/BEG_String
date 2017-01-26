#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String {

  /**Friend means these functions have access to this class (eg. private
     attributes) even if not member functions of it : special authorization **/
  friend String operator+(const String& lhs, const String& rhs);
  friend String operator+(const String& lhs, char rhs);
  friend String operator+(const String& lhs, const char* rhs);

  public :

    // CONSTRUCTORS

    String();
    String(const String &cp);
    String(const char* c_string);

    // DESTRUCTOR

    ~String();

    // MEMBER FUCTIONS

    size_t capacity();
    size_t size();
    size_t max_size();
    size_t length();
    char* c_str();

    bool empty();

    void clear();
    void resize(size_t n, char c = '\0');
    void reserve(int addedSize);

    void print_str_properties(int id);

    //OPERATORS

    String& operator=(const String& right_s);
    String& operator=(const char* c_string);
    String& operator=(char c);

  private :

    //Class attributes
    // Defines maximum size a String can reach
    static const size_t MAX_SIZE = 4294967291;
    //Defines the default capacity we will allow to a String
    static const size_t DEF_SIZE = 255;

    // Character tab
    char* str;

    // Size of tab
    size_t capacity_;
    // Length of String
    size_t size_;

};

    String operator+(const String& lhs, const String& rhs);
    String operator+(const String& lhs, char rhs);
    String operator+(const String& lhs, const char* rhs);

#endif //STRING_H
