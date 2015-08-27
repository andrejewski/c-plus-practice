
#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "Enter a number to be factorizialized: ";
  cin >> num;

  int res = 1;
  for(int i = 0; i < num; i++) {
    res *= (num - i);
  }

  cout << "answers: " << res << endl;

  int zeros = 0;
  while((res % 10) == 0) {
    res /= 10;
    zeros++;
  }

  cout << "zeros: " << zeros << endl;

  return 0;
}

