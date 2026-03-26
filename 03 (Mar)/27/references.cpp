#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void doubleList(vector<int> & numbers) {
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) *it *= 2;
}

void printList(const vector<int> & numbers) {
    // here, we share a reference with our function, to avoid the copy operation that would typically
	// take place, _but_ we share a const reference which is the function promising it won't modify things
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) cout << *it;

    // verboten: we can't do this, because the reference is const, and thus can't be modified
    // for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) *it *= 2;
}

int main (void) {


    vector<int> numbers;
    numbers.push_back(8);
    numbers.push_back(16);

    // in Java or Python, this would create a second reference to the same object
    // in C++, this makes a copy of the original object
    vector<int> powsOfTwo = numbers;

    cout << "Numbers: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) cout << *it << " ";
    cout << endl;

    cout << "powsOfTwo: ";
    for (vector<int>::iterator it = powsOfTwo.begin(); it != powsOfTwo.end(); ++it) cout << *it << " ";
    cout << endl;


    // modify one of the lists -- see that the change only shows up in one place

    powsOfTwo.push_back(32);

    cout << "~~~" << endl;

    cout << "Numbers: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) cout << *it << " ";
    cout << endl;

    cout << "powsOfTwo: ";
    for (vector<int>::iterator it = powsOfTwo.begin(); it != powsOfTwo.end(); ++it) cout << *it << " ";
    cout << endl;



    // do it again, this time, using references instead
    // now, powsRef is an _alias_ for `powsOfTwo`.  It doesn't make a copy -- it just gives it another name.
    vector<int> & powsRef = powsOfTwo;

    powsOfTwo.push_back(64);

    cout << "After adding a new value:" << endl;
    cout << "~~~" << endl;

    cout << "powsOfTwo: ";
    for (vector<int>::iterator it = powsOfTwo.begin(); it != powsOfTwo.end(); ++it) cout << *it << " ";
    cout << endl;

    // we see now the change shows up in both places
    cout << "powsRef: ";
    for (vector<int>::iterator it = powsRef.begin(); it != powsRef.end(); ++it) cout << *it << " ";
    cout << endl;



    // if we pass a reference to a list, we likewise share our existing object instance -- no copy is made
    doubleList(powsOfTwo);

    cout << "After doubling:" << endl;
    cout << "~~~" << endl;

    // thus, we'll get to see the change that the function made
    cout << "powsOfTwo: ";
    for (vector<int>::iterator it = powsOfTwo.begin(); it != powsOfTwo.end(); ++it) cout << *it << " ";
    cout << endl;

    cout << "powsRef: ";
    for (vector<int>::iterator it = powsRef.begin(); it != powsRef.end(); ++it) cout << *it << " ";
    cout << endl;

    return 0;
}
