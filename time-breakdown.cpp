
#include <iostream>
using namespace std;

int main() {
  long int input = 0;

  cout << "Enter seconds to break down: ";
  cin >> input;

  const int MINUTE = 60;
  const int HOUR = MINUTE * 60;

  int hours = input / HOUR;
  int minutes = (input % HOUR) / MINUTE;
  int seconds = (input % HOUR) % MINUTE;

  cout
    << "Hours:   " << hours << endl
    << "Minutes: " << minutes << endl
    << "Seconds: " << seconds << endl;

  return 0;
}

