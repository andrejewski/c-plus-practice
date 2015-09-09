
/*
 * This is just a little playground for printf()
 */


#include <cstdio>
#include <string>
using namespace std;

int main() {

  int num = 12;
  long big_num = 123456789;
  short num_short = 3;
  double decimal_num = 44.8575;

  char* text = "This is text";
  string txt = text;

  printf("%s \n", "Testing printf() syntax");

  printf("C++ string: %s \n", txt.c_str());

  printf("Plain number: %d \n", num);

  printf("Two decimals: %1.2f \n", decimal_num);
  printf("Three decimals: %1.3f \n", decimal_num);

  printf("Math test: %d \n", (5 + 4 * 2));

  return 0;
}



