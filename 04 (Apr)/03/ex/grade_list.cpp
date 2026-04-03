#include "grade_list.h"
#include <cassert>

// You will add function definitions to this file.
// See TODOs in grade_list.h.

double GradeList::min() {
  assert(count > 0);   // no values otherwise
  double minval = grades[0];
  for (int i = 1; i < count; i++) {
    if (grades[i] < minval)
      minval = grades[i];
  }
  return minval;
}

//////////// things to be added for part 2  /////////////////

// TODO: write a constructor (in grade_list.cpp) that has a 
// parameter indicating the starting length of the array. 
GradeList::GradeList(int capacity) : count(0) {
  this->capacity = capacity < 1 ? 1 : capacity;
  grades = new double[this->capacity];
}

// TODO: Add the given grade to the grades list. If the array is full,
// resize it by doubling its length. Do not use realloc!
void GradeList::add(double grade) {
  // check if reaching the capacity
  if (count == capacity) {
    // resize by doubling the size or set it to 1 if it is an empty array
    if (capacity)
      capacity *= 2;
    else
      capacity = 1;

    double *temp = new double[capacity];

    for (int i = 0; i < count; ++i) {
      temp[i] = grades[i];
    }
    if (grades)
      delete[] grades;

    grades = temp;
  }
  grades[count++] = grade;
}

// TODO: Add the specified number of values from an array of 
// grades to this object.
void GradeList::add(int howmany, double *grades) {
  // add all elements in the input array to the grade list
  for (int i = 0; i < howmany; ++i) {
    add(grades[i]);
  }
}


// TODO: write a function (in grade_list.cpp) to clear the list
// of all values, making the array as small as possible
void GradeList::clear() {
  if (grades)
    delete [] grades;
  capacity = 1;
  grades = new double[capacity];
  count = 0;
}

// Added a default constructor
GradeList::GradeList() : capacity(1), count(0) {
  grades = new double[1];
}

// Added a destructor to release memory
GradeList::~GradeList() {
  delete [] grades;
}


// bonus copy constructor
GradeList::GradeList(const GradeList & from) {
  this->count = from.count;
  this->capacity = from.capacity;
  
  this->grades = new double[capacity];
  for (int i=0; i < count; i++) {
    this->grades[i] = from.grades[i];
  }
}
