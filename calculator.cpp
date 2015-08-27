
#include <cstring>
#include <iostream>
#include <stdexcept>
using namespace std;

enum operation {
  ADD,
  SUBTRACT,
  MULTIPLY,
  DIVIDE
};

struct Calculation {
  operation op;
  double left;
  double right;
};

Calculation calculationFromStr(char str[]) {
  // left op right
  char sep[] = " ";
  int pos = 0;

  Calculation calc;

  char * pch;
  pch = strtok(str, sep);
  while(pch != NULL && pos < 3) {
    switch(pos) {
      case 0:
        calc.left = stod(pch);
        break;
      case 1:
        if(strcmp(pch, "+") == 0) {
          calc.op = ADD;
        } else if(strcmp(pch, "-") == 0) {
          calc.op = SUBTRACT;
        } else if(strcmp(pch, "*") == 0) {
          calc.op = MULTIPLY;
        } else if(strcmp(pch, "/") == 0) {
          calc.op = DIVIDE;
        } else {
          throw invalid_argument("recieved an unsupported operator");
        }
        break;
      case 2:
        calc.right = stod(pch);
        break;
    }
    pch = strtok(NULL, sep);
    pos++;
  }

  return calc;
}

double computeCalculation(Calculation calc) {
  switch(calc.op) {
    case ADD: return calc.left + calc.right;
    case SUBTRACT: return calc.left - calc.right;
    case MULTIPLY: return calc.left * calc.right;
    case DIVIDE: return calc.left / calc.right;
  }
}

char* readline() {
  string readline;
  getline(cin, readline);
  char *str = new char[readline.length() + 1];
  strcpy(str, readline.c_str());
  return str;
}

int main() {
  char * input;
  char quit[] = "q";
  cout << "I am calculator. Enter 'q' to quit. Enter maths:" << endl;
  input = readline();
  while(strcmp(input, quit) != 0) {
    Calculation calc = calculationFromStr(input);
    double answer = computeCalculation(calc);
    cout << answer << endl;
    input = readline();
  }
  return 0;
}

