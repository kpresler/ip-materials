#include <iostream>


using std::cout;
using std::endl;

class Demo {

    public:
        Demo(int num) {
            cout << "In Demo constructor" << endl;
            this -> num = num;
        }

        Demo(const Demo & other) {
            cout << "In Demo copy constructor" << endl;
            this -> num = other.num;
        }

        Demo & operator=(const Demo & other) {
            cout << "In Demo assignment function" << endl;
            this -> num = other.num;
            return *this;
        }


        // breaking encapsulation for part of the example
        int num;


};

void printDemo(Demo toPrint) {
    cout << toPrint.num << endl;
}

int main (void) {

    cout << "Demo d1 (100); " << endl;
    Demo d1 (100);

    cout << endl << "Demo d2 {100}; " << endl;
    Demo d2 = {200};

    cout << endl << "Demo d3 = Demo(300);" << endl;
    Demo d3 = Demo(300);

    // this calls the copy constructor

    // implicitly calling the copy constructor
    cout << endl << "Demo d4 = d2;" << endl;
    Demo d4 = d2;

    // explicitly calling the copy constructor
    cout << endl << "Demo d5 (d1);" << endl;
    Demo d5 (d1);

    // implicitly calling copy constructor when making a function call
    cout << endl << "printDemo(d4);" << endl;
    printDemo(d4);

    // and this calls the assignment operator
    cout << endl << "d3 = d2;" << endl;
    d3 = d2;


}
