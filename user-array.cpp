
/*
 * User manaully builds an array of the size of their choosing.
 * #iostream #array
 */

#include <iostream>
using namespace std;

int main() {
  int len;
  cout << "Length of array: ";
  cin >> len;

  int arr[len];
  for(int i = 0; i < len; i++) {
    cout << "Value at index " << i << ": ";
    cin >> arr[i];
  }

  for(int j = 0; j < len; j++) {
    cout << "[" << arr[j] << "]" << endl;
  }

  char c;
  cout << "Enter 'q' to quit:";
  cin >> c;

  return 0;
}

