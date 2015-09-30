
/*
  Sequential Search

  Worst Case Performance: O(n)
    The target is at the very end of the list,
    all elemeents need to be accessed and compared.
  Best Case Performance: O(1)
    The target is the first element compared.
  Average Case Performance: O(n)
    Between O(1) and O(n), O(n) being most likely.
  Worst Case Space Complexity: O(1)
    Search operates only on the given input.

  Compared to Binary Search:
    - Slower, but the elements do not need to be sorted.
    - Only operator== needs to be implemented, there does
      not have to be a way to order the elements.
*/

#include <vector>
#include <assert.h>
using namespace std;

int sequentialSearch(const int* array, const int len, const int query) {
  for(int i = 0; i < len; i++) {
    if(array[i] == query) return i;
  }
  return -1;
}

template<class T, class V>
int sequentialSearch(const T &container, const V query) {
  int len = container.size();
  for(int i = 0; i < len; i++) {
    if(container[i] == query) return i;
  }
  return -1;
}

void sequentialSearchTest() {
  {
    int array[] = {1,3,4,7,9,10};
    int len = 6;

    int pos1 = sequentialSearch(array, len, 7);
    assert(pos1 == 3);

    int pos2 = sequentialSearch(array, len, 2);
    assert(pos2 == -1);
  }

  {
    static const int elems[] = {1,3,4,7,9,10};
    vector<int> vec (elems, elems + 6);

    int pos1 = sequentialSearch<vector<int>, int>(vec, 7);
    assert(pos1 == 3);

    int pos2 = sequentialSearch<vector<int>, int>(vec, 2);
    assert(pos2 == -1);
  }
}

int main() {
  sequentialSearchTest();
  return 0;
}

