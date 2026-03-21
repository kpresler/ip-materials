#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;

int main (void) {

    vector<int> numbers;
    for (int i = 0; i < 20; i++) numbers.push_back(rand() % 100);

    cout << "Our original list, full of random junk:" << endl;
    for (int i = 0; i < numbers.size(); i++) cout << numbers.at(i) << " ";
    cout << endl;

    std::sort(numbers.begin(), numbers.end());

    cout << endl << "List full of random junk, but now sorted junk: " << endl;
    for (int i = 0; i < numbers.size(); i++) cout << numbers.at(i) << " ";
    cout << endl;


    std::fill(numbers.begin(), numbers.begin() + 3, 1111);

    cout << endl << "Filling the first 3 slots with 1111: " << endl;
    for (int i = 0; i < numbers.size(); i++) cout << numbers.at(i) << " ";
    cout << endl;


    cout << endl << "We've got " << std::count(numbers.begin(), numbers.end(), 1111) << " 1111s" << endl;



    int * numbersPtr = (int *) malloc(10 * sizeof(int));

    std::fill(numbersPtr, numbersPtr + 10, 20);


    cout << endl << "Using fill on an array: " << endl;
    for (int i = 0; i < 10; i++) cout << numbersPtr[i] << " ";
    cout << endl;
	
    free(numbersPtr);


    return 0;
}
