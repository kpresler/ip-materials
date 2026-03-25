#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

// we'll talk about references next class -- that's what the `&` is
// for now, you can just ignore it
void writeRandomNumbers(std::ostream & output, int count) {

    for (int i = 0; i < count; i++) output << rand() % 100 << endl;

}

int main (void) {


    string fileName;
    int count;

    cout << "Enter a file to write to, and how many numbers to write: " << endl;

    cin >> fileName >> count;

    std::ofstream outputFile(fileName);

    writeRandomNumbers(outputFile, count);

    cout << "Done!" << endl;

    // but, we can do the same thing....just using stdout as our output stream

    writeRandomNumbers(cout, count);

    std::ostringstream oss;

    writeRandomNumbers(oss, count);

    cout << "The contents of our stringstream is: `" << oss.str() << "`" << endl;

    return 0;
}
