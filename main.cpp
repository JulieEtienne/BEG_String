#include "String.h"

int main(int argc, char const *argv[])
{
  printf("\nTP de Cpp\n");

  //Default constructor test
  String test;

  //Copy constructor test
  String test2(test);

  //C-string constructor test
  String test3("coucou");

  //C-string method test
  printf("\n Test c-string :\t %s", test3.c_str());


  printf("\nEND\n");
  return 0;
}