#ifndef STRING_H
#define STRING_H

#include <cstdio>
#include <cstdlib>

class String {

  public :

    // CONSTRUCTORS

    String();
    String(const String &cp);
    String(const char* c_string); // Constructor using a c-string

    // DESTRUCTOR

    ~String();

    // MEMBER FUCTIONS
    void print_str_properties(int id);


    size_t capacity();
    size_t size();
    size_t max_size();
    size_t length();
    
    bool empty();

    char* c_str();

    void resize(size_t n, char c = '\0');
    void reserve(int addedSize);

    //OPERATORS
    String operator+(const String& left_s);
    
    String& operator=(const String& left_s);
    String& operator=(const char* c_string);
    String& operator=(char c);



  private :

    // defines maximum size a string can reach
    const size_t MAX_SIZE = 4294967291;

    char* str;        // character tab

    size_t capacity_; // size of tab
    size_t size_;     // length of string

};

#endif //STRING_H
