
#include <iostream>
using namespace std;

enum scale {CELCIUS, FARENHEIT};

double toCelcius(double temp) {
  return ((temp - 32) * 5) / 9;
}

double toFarenheit(double temp) {
  return ((9*temp)/5) + 32;
}

int main() {
  char* input_unit;
  scale unit;
  double temp;

  cout << "Choose to convert from celcius or farenheit: ";
  cin >> input_unit;
  char init = input_unit[0];
  if(init == 'c' || init == 'C') {
    unit = CELCIUS;
  } else {
    unit = FARENHEIT;
  }

  cout << "Enter the temperature: ";
  cin >> temp;

  if(unit == CELCIUS) {
    cout << toFarenheit(temp) << " F\n";
  } else {
    cout << toCelcius(temp) << " C\n";
  }

  return 0;
}

