
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  char* filename;
  if(argv[1] != NULL) {
    filename = argv[1];
  } else {
    throw invalid_argument("destination filename must be given");
  }
  ofstream dest;
  dest.open(filename);
  if(dest.is_open()) {
    cout << "Begin entering lines of text:" << endl;
    string line;
    getline(cin, line);
    while(strcmp(line.c_str(), ":q") != 0) {
      dest << line << endl;
      getline(cin, line);
    }
    dest.close();
  } else {
    cout << "Could not open file." << endl;
    return 1;
  }

  cout << "File written." << endl;
  return 0;
}

