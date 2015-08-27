
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int count = 0;
  char* filename;
  if(argv[1] != NULL) {
    filename = argv[1];
  } else {
    // do a exec file line count
    filename = argv[0];
  }
  ifstream file;
  file.open(filename);
  if(file.is_open()) {
    string line;
    cout << "Counting lines of " << filename << endl;
    while(getline(file, line)) {
      count++;
    }
    file.close();
  }
  cout << "Line count: " << count << endl;
}

