#include <iostream>
#include <stdio.h>
using namespace std;

class Array {
private:
  int capacity;
  int lastIndex;
  int *ptr;

public:
  Array(int);
  bool isEmpty();
  bool isFull();
  void append(int);
  void insert(int, int);
  void edit(int, int);
  void del(int);
};

Array::Array(int size) {

  if (size > 0) {
    capacity = size;
    lastIndex = -1;
    ptr = new int[capacity];
  } else
    ptr = NULL;
}
bool Array::isEmpty() { return lastIndex == -1; }
bool Array::isFull() { return lastIndex == capacity - 1; }
void Array::append(int data) {
  if (isFull())
    cout << "\nOverflow";
  else {
    lastIndex++;
    ptr[lastIndex] = data;
  }
}
void Array::insert(int index, int data) {

  if (index < 0 || index > lastIndex + 1)
    cout << "\nInvalid Index";
  else if (isFull())
    cout << "\nOverFlow";
  else {
    for (int i = lastIndex; i >= index; i--) {
      ptr[i + 1] = ptr[i];
    }
    ptr[index] = data;
    lastIndex++;
  }
}
void Array ::edit(int index, int data) {

  if (index < 0 || index > lastIndex)
    cout << "\n Invalid Index or empty array";
  else {
    ptr[index] = data;
  }
}
void Array ::del(int index) {
  int i;
  if (index < 0 || index > lastIndex)
    cout << "\n Invalid Index or empty array";
  else {
    for (i = index; i <= lastIndex; i++)
      ptr[i] = ptr[i + 1];
    lastIndex--;
  }
}
