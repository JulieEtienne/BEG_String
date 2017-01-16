#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String {

  public :

    char* c_str();

  //CONSTRUCTORS
    String();
    String(const String &cp);
    String(char* c_string); // Constructor using a c-string


  protected :


  private :
    char* str; // character tab

    size_t capacity_; // size of tab
    size_t size_; // length of string 




};

#endif //STRING_H
