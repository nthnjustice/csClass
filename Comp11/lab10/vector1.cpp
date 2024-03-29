// A dynamic array with fixed size
#include "vector1.h"

// -- Initialize a vector ---
//   args: capacity of the Vector

Vector::Vector(int cap) {
   capacity = cap;
   data = new int[capacity];
   n_elements = 0;
}

// -- Destroys a vector ---

Vector::~Vector() {
   delete [] data;
}

// -- Returns size of the Vector ---
//   rets: number of elements in the Vector

int Vector::getSize() {
   return n_elements;
}

// -- Returns element at the given index ---
//   args: index of the element
//   rets: element at the given index

int Vector::get(int index) {
   return data[index];
}

// -- Adds the given element to end of the array ---
//   args: element to be added
//   rets: true if element is successfully added, false otherwise

bool Vector::add(int element) {
  if(nelements < capacity){
    data[nelements1] = element;
    nelements++;
    return true;
  }
  else{
    return false;
  }
}

// -- Places the given element at the given index ---
//   args: element and index
//   errs: quits if too much data
//   rets: true if element is successfully added, false otherwise

bool Vector::add(int element, int index) {
}
