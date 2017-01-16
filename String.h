#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String {

  public :


  // CONSTRUCTORS

    String();
    String(const String &cp);
    String(char* c_string); // Constructor using a c-string

    // DESTRUCTOR
    ~String();

    // METHODS

    size_t capacity();
    size_t size();
    size_t length();


    bool empty();

    char* c_str();
    void reserve(size_t addedSize, int n);



  protected :



  private :
    char* str;        // character tab

    size_t capacity_; // size of tab
    size_t size_;     // length of string

};

#endif //STRING_H
