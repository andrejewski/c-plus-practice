
/*
  This example provides uses for higher-order functions
  via C++ style function callbacks.

  Select, best known as map.
  Filter, best known as filter.
  Reduce, also known as fold[l].
*/

#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
vector<T> select(vector<T> vec, T (*mapper)(T)) {
  vector<T> res;
  typename vector<T>::iterator it;
  for(it = vec.begin(); it != vec.end(); it++) {
    res.push_back((*mapper)(*it));
  }
  return res;
}

template<typename T>
vector<T> filter(vector<T> vec, bool (*predicate)(T)) {
  vector<T> res;
  typename vector<T>::iterator it;
  for(it = vec.begin(); it != vec.end(); it++) {
    if((*predicate)(*it)) res.push_back(*it);
  }
  return res;
}

template<typename T, typename X>
X reduce(vector<T> vec, X (*accumalator)(X, T), X memo) {
  typename vector<T>::iterator it;
  for(it = vec.begin(); it != vec.end(); it++) {
    memo = (*accumalator)(memo, *it);
  }
  return memo;
}

int triple(int n) {
  return n * 3;
}

bool isEven(int x) {
  return !(x % 2);
}

int sum(int total, int next) {
  return total + next;
}

int main() {
  int arr[] = {8, 1, 7, 2, 6, 3, 5, 4};
  vector<int> list(arr, arr + 8);

  vector<int> mul3 = select(list, &triple);
  vector<int> even = filter(mul3, &isEven);

  int sortedSum = reduce(sorted, &sum, 0);
  int evenSum = reduce(even, &sum, 0);

  return 0;
}

