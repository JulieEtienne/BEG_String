#include "String.h"
#include <iostream>




int main()
{
  printf("\nTP de Cpp\n");

  //----- CONSTRUCTOR TESTS

  //Default constructor test
  String test;

  //Copy constructor test
  String test2(test);

  //C-string constructor test
  String test3("coucou");

  //String >DEF_SIZE characters
  String test4("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Bigger >:)");

  //Print str properties test
  test4.print_str_properties(4);

  //----- GETTER TESTS

  //C-string method test
  printf("\n Test c-string :\t %s\n", test3.c_str());

  //Empty method test
  printf("\n Is empty test3:\t %s\n", test3.empty()? "True":"False");
  printf("\n Is empty test2:\t %s\n", test2.empty()? "True":"False");

  //Capacity method test
  printf("\n Capacity of test 3 :\t %d\n", (int)test3.capacity());

  //Size method test (same as length)
  printf("\n Size of test 3 :\t %d\n", int(test3.size()));

  //Max_size method test
  std::cout<<"\n"<<test3.max_size()<<std::endl;
  //printf("\n Max_size : \t%d\n", test3.max_size());

  
  //----- METHOD TESTS

  //Reserve method test
  test3.reserve(20);
  printf("\n Capacity of test 3 after reserve :\t %d\n", int(test3.capacity()));

  //Clear test
  test3.clear();
  test3.print_str_properties(3);

  //Resize test
  test3.resize(9, 'u');
  test3.print_str_properties(3);

  test3.resize(18); 
  test3 = test3 + 'a';
  test3.print_str_properties(3);



  //----- OPERATOR TESTS

  //Operator+ test String
  String test0(test3 + test4);
  test0.print_str_properties(0);
  
  //Operator+ test char
  String testx = "l'hibou niche ";
  String testy = testx + 'o' ;  
  testy.print_str_properties(42);

  //Operator+ for char*
  test3.resize(300,'u');
  char test_c[10] = "Hello";
  String testz = test3 + test_c;

  testz.print_str_properties(20);
  testz = testz + " cou cou";
  testz.print_str_properties(2);


  //Operator= test for copy, +operator by string
  test = test3 + test0;
  test.print_str_properties(1200);

  //Operator= test for c_str
  test = "re-coucou";
  test.print_str_properties(1);

  //Operator= test for char
  test = 'a';   //Note : also works if character is empty
  test.print_str_properties(1);


  printf("\nEND\n");

  return 0;
}
