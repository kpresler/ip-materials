/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: Write a program that declares a GradeList
 *       variable and adds to it all the even
 *       numbers 0-100:
 *       
 *       {0, 2, 4, ..., 98, 100}
 * 
 *       then prints out the minimum, maximum,
 *       median, mean and 75th percentile, all
 *       nicely labelled.
 */

#include <iostream>
#include "grade_list.h"

int main(void) {
  GradeList gl;

  // add all even number 0-100
  for (int i = 0; i <= 100; i += 2) {
    gl.add(i);
  }

  std::cout << "Mean: " << gl.mean() << std::endl;
  std::cout << "Min: " << gl.percentile(0) << std::endl;
  std::cout << "Max: " << gl.percentile(100) << std::endl;
  std::cout << "Median: " << gl.median() << std::endl;
  std::cout << "75th percentile: " << gl.percentile(75) << std::endl;

  return 0;
}
