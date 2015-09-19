
#include <iostream>
#include <assert.h>

template <class T>
class BinarySearchTree {
  BinarySearchTree<T> *left;
  BinarySearchTree<T> *right;
  T value;

  public:
    BinarySearchTree<T>(
      const T nodeValue,
      BinarySearchTree<T> *leftNode = NULL,
      BinarySearchTree<T> *rightNode = NULL) {
        value = nodeValue;
        left = leftNode;
        right = rightNode;
    }

    T getValue() { return value; }
    void setValue(const T val) { value = val; }

    BinarySearchTree<T> *leftNode() {
      return left;
    }

    BinarySearchTree<T> *rightNode() {
      return right;
    }

    BinarySearchTree<T> *leftmostNode() {
      if(left == NULL) return this;
      return left->leftmostNode();
    }

    BinarySearchTree<T> *rightmostNode() {
      if(right == NULL) return this;
      return right->rightmostNode();
    }

    BinarySearchTree<T> *query(const T search) {
      if(value == search) return this;
      if(left != NULL) {
        BinarySearchTree<T> *result = left->query(search);
        if(result != NULL) return result;
      }
      if(left != NULL) {
        BinarySearchTree<T> *result = right->query(search);
        if(result != NULL) return result;
      }
      return NULL;
    }

    BinarySearchTree<T> *predecessor(const BinarySearchTree<T> *node) {
      if(left == NULL) return NULL;
      return left->rightmostNode();
    }

    BinarySearchTree<T> *successor(const BinarySearchTree<T> *node) {
      if(right == NULL) return NULL;
      return right->leftmostNode();
    }

    void insert(const T key) {
      if(key == value) return; // no duplicate keys
      if(key < value) {
        if(left == NULL) {
          left = new BinarySearchTree<T>(key);
        } else {
          left->insert(key);
        }
      } else {
        if(right == NULL) {
          right = new BinarySearchTree<T>(key);
        } else {
          right->insert(key);
        }
      }
    }

    bool remove(const T key) {
      if(key == value) return false; // cannot remove parent from self
      if(key < value) {
        if(left == NULL) return false;
        if(left->getValue() == key) {
          BinarySearchTree<T> *ls = left->leftNode();
          BinarySearchTree<T> *rs = left->rightNode();
          if(ls == NULL && rs == NULL) {
            left = NULL;
          } else if(ls == NULL) {
            left = rs;
          } else if(rs == NULL) {
            left = ls;
          } else {
            BinarySearchTree<T> *pred = predecessor(left);
            left->setValue(pred->getValue());
            return left->rightNode()->remove(pred->getValue());
          }
          return true;
        } else {
          return left->remove(key);
        }
      } else {
        if(right == NULL) return false;
        if(right->getValue() == key) {
          BinarySearchTree<T> *ls = right->leftNode();
          BinarySearchTree<T> *rs = right->rightNode();
          if(ls == NULL && rs == NULL) {
            right = NULL;
          } else if(ls == NULL) {
            right = rs;
          } else if(rs == NULL) {
            right = ls;
          } else {
            BinarySearchTree<T> *pred = predecessor(right);
            right->setValue(pred->getValue());
            return right->rightNode()->remove(pred->getValue());
          }
          return true;
        } else {
          return right->remove(key);
        }
      }
    }

    int size() {
      return 1
        + (left  == NULL ? 0 : left->size())
        + (right == NULL ? 0 : right->size());
    }
};

int main() {
  typedef BinarySearchTree<int> BST;

  BST root(10);

  assert(root.size() == 1);
  assert(root.getValue() == 10);
  assert(root.query(root.getValue()) == &root);

  root.insert(5);

  assert(root.query(5) != NULL);
  assert(root.size() == 2);

  root.insert(15);

  assert(root.leftNode()->getValue() == 5);
  assert(root.rightNode()->getValue() == 15);
  assert(root.size() == 3);

  root.insert(12);

  assert(root.rightNode()->leftNode()->getValue() == 12);
  assert(root.size() == 4);

  root.remove(15);

  assert(root.size() == 3);
  assert(root.query(15) == NULL);
  assert(root.rightNode()->getValue() == 12);

  return 0;
}

