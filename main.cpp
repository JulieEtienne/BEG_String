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

  //String of >255 char
  String test4("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Bigger >:)");

  test4.print_str_properties(4);


  //C-string method test
  printf("\n Test c-string :\t %s\n", test3.c_str());

  //empty method test
  printf("\n Is empty test3:\t %s\n", test3.empty()? "True":"False");
  printf("\n Is empty test2:\t %s\n", test2.empty()? "True":"False");

  //capacity method test
  printf("\n Capacity of test 3 :\t %d\n", (int)test3.capacity());

  //size method test
  printf("\n Size of test 3 :\t %d\n", (int)test3.size());

  //reserve method test
  test3.reserve(20);
  printf("\n Capacity of test 3 after reserve :\t %d\n", int(test3.capacity()));

  //+operator test

  String test0(test3 + test4);

  test4.print_str_properties(0);
  
  //+operator test (char)
  String testChar = "l'hibou niche ";
  String resultChar = testChar + 'o' ;
  
  resultChar.print_str_properties(42);

  //=operator test for copy, +operator by string
  test = test3 + test0;
  test.print_str_properties(1200);

  //=operator test for c_str
  test = "re-coucou";
  test.print_str_properties(1);

  //=operator test for char
  test = 'a';   //Note : also works if character is empty
  test.print_str_properties(1);

  //resize test
  test3.resize(300,'u');
  test3.print_str_properties(3);

  //clear test
  test3.clear();
  test3.print_str_properties(3);

  test3.resize(300,'u');


  //+operator for char*
  char test_[10] = "Hello";
  String t = test3 + test_;
  t.print_str_properties(20);
  t = t + " cou cou";
  t.print_str_properties(2);

  printf("\nEND\n");

  return 0;
}
