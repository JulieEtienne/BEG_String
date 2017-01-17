#include "String.h"

int main()
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

  //empty method test
  printf("\n Is empty test3:\t %s", test3.empty()? "True":"False");
  printf("\n Is empty test2:\t %s", test2.empty()? "True":"False");

  //capacity method test
  printf("\n Capacity of test 3 :\t %d", (int)test3.capacity());

  //size method test
  printf("\n Size of test 3 :\t %d", (int)test3.size());

  //resize test
  test3.resize(12, 'b');
  printf("\n Resized Coucou :\t %s", test3.c_str());





  printf("\nEND\n");

  return 0;
}
