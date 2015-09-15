
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
  string name;
  char code;
  int hours;

  cout << "Enter employee's name: ";
  getline(cin, name);

  cout << "M=Manager, P=Programmer, A=Admin" << endl;
  cout << "Enter employee code: ";
  cin >> code;

  cout << "Enter hours worked: ";
  cin >> hours;

  string title;
  double rate;

  if(code == 'A') {
    title = "Administrator";
    rate = 15.45;
  }

  if(code == 'P') {
    title = "Programmer";
    rate = 25.00;
  }

  if(code == 'M') {
    title = "Manager";
    rate = 42.50;
  }

  double wage;
  if(hours > 40) {
    wage = (40 * rate) + ((hours - 40) * rate * 1.5);
  } else {
    wage = hours * rate;
  }

  int nameWidth = name.length() + 1;
  int titleWidth = title.length() + 1;
  int rateWidth = 12; // "Hourly Wage".length() + 1
  int workedWidth = 14; // "Hours Worked".length() + 1
  int weeklyWidth = 12; // "Weekly Wage".length() + 1

  cout
    << left
    << setw(nameWidth) << "Name "
    << setw(titleWidth + 2) << "| Title "
    << right
      << setw(rateWidth) << "| Hourly Rate "
      << setw(workedWidth) << "| Hours Worked "
      << setw(weeklyWidth) << "| Weekly Wage "
    << left << endl;

  cout
    << setw(nameWidth) << name
    << "  " << setw(titleWidth) << title
    << right << fixed
      << " $" << setw(rateWidth - 1) << setprecision(2) << rate
      << "  " << setw(workedWidth - 1) << hours
      << "  $" << setw(weeklyWidth - 1) << setprecision(2) << wage
    << left << endl;

  return 0;
}

