
// unfinished

#include <iostream>
#include <stdexcept>
using namespace std;

void pad(int num) {
  if(num >= 1000) {
    throw invalid_argument("Cannot print numbers greater than 999");
  }
  if(num >= 100) {
    cout << num;
  } else if(num >= 10) {
    cout << " " << num;
  } else {
    cout << " " << num << " ";
  }
}

long factorial(int n) {
  long res = 1;
  for(int i = 0; i < n; i++) {
    res *= n - i; 
  }
  return res;
}

int main() {
  int rows;
  cout << "How many rows to generate? ";
  cin >> rows;

  char space = ' ';

  int rowlen = rows * (3 + 2);

  for(int cur = 1; cur <= rows; cur++) {
    int empty_space = rowlen - (cur * 5);
    int side_space = empty_space / 2;
    for(int i = 0; i < side_space; i++) {
      cout << space;
    }

    for(int col = 0; col < cur; col++) {
      cout << space;
      if(col == 0 || (col + 1) == cur) {
        pad(1);
      } else {
        /* pad((rows - col) / (col + 1)); */
        pad(factorial(cur) / (factorial(col) * factorial(cur - col)));
      }
      cout << space;
    }


    for(int j = 0; j < side_space; j++) {
      cout << space;
    }
    cout << endl;
  }
}

