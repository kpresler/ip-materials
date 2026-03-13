#include <iostream> // for C++ console IO
#include <cstdio> // if we wanted to use C's printf, scanf, etc
#include <string>

// main has exactly the same signature as before
// we can also write a version that accepts command-line arguments:
// int main (int argc, char ** argv) { ... }
int main (void) {

    // we print by left shifting to the cout stream
    std::cout << "Hello, world!" << std::endl;

    std::cout << "Please enter a number:" << std::endl;

    std::string in;

    // Reading is done by right-shifting cin into your variable
    std::cin >> in;

    // stoi = string to int
    int num = stoi(in);


    if (num < 10) {
        std::cout << "That was a bad number :(" << std::endl;
    }
    else {
        std::cout << "Good choice!" << std::endl;

    }

    // if you get tired of all of this `std::`, there's a solution

    using std::cout;
    using std::endl;
    using std::cin;

    // note, do not just do `using namespace std` -- yes, it's tidier
    // but it imports _all_ of the namespace, which defeats why we split
    // things up into namespaces in the first place.

    cout << "Enter as many numbers as you want, one at a time " << endl;

    int sum = 0;
    // this seems a lot nicer than the scanf solution :)
    while (cin >> in) {
        sum += stoi(in);

    }

    // Like with System.out.println in Java, you can build up a long sequence
    // of stuff to print using <<
    cout << "The total sum of all of your numbers was " << sum << endl;

    // always good practice!
    return 0;
}
