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
    size_t max_size();
    size_t length();
    
    bool empty();
    void reserve(size_t addedSize, int n);


    char* c_str();


  protected :



  private :
    const size_t MAX_SIZE = 4294967291; // defines maximum size a string can reach

    char* str; // character tab

    size_t capacity_; // size of tab
    size_t size_;     // length of string

};

#endif //STRING_H
