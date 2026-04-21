#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

/* Collect integers from a file; store them in a vector */
std::vector<int> readFile(char* filename) {
  std::ifstream fin(filename);
  std::vector<int> numbers(10);

  if( !fin.is_open() )
    throw std::ios_base::failure( "Couldn't open file" );

  int n = 0;
  size_t index = 0;
  while(true) {
    fin >> n;
    if (fin.eof()) { // if we're out of file, return
      return numbers;
    }
    if (fin.fail()) { // if we failed to read an int, throw an exception
      throw std::invalid_argument("File contains non-integer data!\n");
    }

    // try to add the element to the list -- if out of space, make more space
    // this is really just demonstrating the mechanics -- using `push_back` and letting
    // the list resize itself is clearly better
    try {
      numbers.at(index) = n;
    }
    catch( std::out_of_range e ) {
      numbers.resize( numbers.size() * 2 );
      numbers.at(index) = n;
    }
    index++;
  }

  throw std::logic_error("ERROR: should never get here!");
  return numbers;
}


int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: program requires a filename as an argument\n";
    return 0;
  }

  std::vector<int> numbers;

  // try calling our function, handling the things that can go wrong in the process
  try {
      numbers = readFile( argv[1] );
  }

  // different catch blocks for different types of problems
  catch( std::out_of_range e ) {
      std::cerr << "Too many numbers in file" << std::endl;
      return 1;
  }
  catch( std::ios_base::failure e ) {
      std::cerr << e.what() << std::endl;
      return 1;
  }
  catch( std::invalid_argument e ) {
      std::cerr << e.what() << std::endl;
      return 1;
  }

  std::cout << "Read numbers: ";
  for(int &i : numbers) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
