
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

void vectorPractice() {
  // initialize a empty vector
  vector<int> vec;

  // initialize a vector with many values
  int vals[] = {1, 2, 3};
  vector<int> vex(vals, vals + 3);

  // get the first value
  assert(1 == vex.front());

  // get the last value
  assert(3 == vex.back());

  // add to a vector
  vec.push_back(2);
  assert(vec[0] == 2);

  // remove from a vector
  vex.pop_back();
  assert(vex.back() == 2);

  // get the size of a vector
  int size_c = vec.size();
  assert(size_c == 1);
  int size_x = vex.size();
  assert(size_x == 2);

  // loop a vector
  int len = vex.size();
  for(int i = 0; i < len; i++) {
    assert(vex[i] - 1 == i);
  }

  // iterate a vector (using iterators)
  vector<int>::iterator it;
  for(it = vex.begin(); it != vex.end(); it++) {
    int val = *it;
    int idx = it - vex.begin();
    assert(val - 1 == idx);
  }

}

void mapPractice() {
  // initialize an empty map
  map<int, string> ismap;

  // initialize a map with many values
  typedef pair<int, string> pis;
  pis a(1, "yes");
  pis b(2, "no");
  pis c(3, "maybe");

  pis pairs[] = {a, b, c};
  map<int, string> iter(pairs, pairs + 3);

  // get a value:
  assert(iter[1] == "yes");

  // set a value:
  iter[3] = "probably";
  assert(iter[3] == "probably");

  // iterate a map using iterators
  map<int, string>::iterator it;
  int idx = 0;
  for(it = iter.begin(); it != iter.end(); it++) {
    int key = it->first;
    assert(key == ++idx);
  }

}

void stackPractice() {
  // initialize an empty stack
  stack<int, vector<int> > ste;

  // initialize a stack with a container
  int vals[] = {1, 2, 3};
  vector<int> vec(vals, vals + 3);
  stack<int, vector<int> > stvec(vec);

  // initialize a stack with many values
  // not possible, need to populate and pass
  // a container instance

  // get size
  assert(stvec.size() == 3);

  // peek top value
  assert(stvec.top() == 3);

  // push onto stack
  stvec.push(4);
  assert(stvec.top() == 4);

  // pop off of stack
  stvec.pop();
  assert(stvec.top() == 3);

}

void queuePractice() {
  /*
   std::queue<T, container<T> > q
    T front()
      => container.front()
      => container[0]
    T back()
      => container.back()
      => container[size() - 1]
    void push(T)
      => container.push_back()
    void pop()
      => container.pop_front()
  */
}

int main() {
  vectorPractice();
  mapPractice();

  stackPractice();
  queuePractice();
  return 0;
}

