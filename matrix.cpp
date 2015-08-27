
#include <iostream>
using namespace std;

int main() {
  int len = 4;
  int mat[len][len];

  for(int i = 0; i < len; i++) {
    for(int j = 0; j < len; j++) {
      mat[i][j] = 1;
    }
  }

  for(int i = 0; i < len; i++) {
    for(int j = 0; j < (len/2); j++) {
      mat[i][j] *= 3;
    }
  }

  for(int i = 0; i < (len/2); i++) {
    for(int j = 0; j < len; j++) {
      mat[i][j] *= 5;
    }
  }

  cout << "[" << endl;
  for(int i = 0; i < len; i++) {
    cout << "  [";
    for(int j = 0; j < len; j++) {
      cout << mat[i][j];
      if(j + 1 != len) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;

  return 0;
}

