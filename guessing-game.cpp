
#include <iostream>
#include <time.h>
using namespace std;

enum result {HIGH, LOW, MATCH};

result guess(int num) {
  int val;
  cout << "Guess a number: ";
  cin >> val;
  if(val == num) return MATCH;
  if(val > num) {
    return HIGH;
  } else {
    return LOW;
  }
}

int random(int min, int max) {
  srand(time(NULL));
  return rand() % (max - min) + min;
}

int main() {
  int cur_attempts = 1;
  int max_attempts = 8;
  int num = random(0, 20);
  while(cur_attempts != max_attempts) {
    switch(guess(num)) {
      case HIGH:
        cout << "Your guess was high." << endl;
        break;
      case LOW:
        cout << "Your guess was low." << endl;
        break;
      case MATCH:
        cout << "You guessed correctly!" << endl;
        cout << "It took you " << cur_attempts << " attempts." << endl;
        return 0;
    }
    cur_attempts += 1;
  }

  cout << "You didn't guess the correct number within " << max_attempts << " attmepts." << endl;
  cout << "The number was " << num << "." << endl;
  return 0;
}

