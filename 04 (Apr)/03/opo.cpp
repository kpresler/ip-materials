#include <iostream>
#include <string>

using std::string;


string operator+(const string & left, const int & right) {
    return left + std::to_string(right);
}

using std::cout;
using std::endl;

int main (void) {


    string txt("Hello, world!");

    txt = txt + 25;

    cout << txt << endl;

    return 0;

}


