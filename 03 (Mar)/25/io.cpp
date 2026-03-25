#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

int main (void) {
    string fileName;
    int count;

    cout << "Enter a file to write to, and how many numbers to write: " << endl;

    cin >> fileName >> count;

    std::ofstream outputFile(fileName);

    for (int i = 0; i < count; i++) outputFile << rand() % 100 << endl;

    cout << "Done!" << endl;

    std::ifstream inputFile(fileName);

    int num;

    long prod = 1;
    while (inputFile >> num) prod *= num;

    cout << "The product of all numbers is " << prod << endl;

    return 0;
}
