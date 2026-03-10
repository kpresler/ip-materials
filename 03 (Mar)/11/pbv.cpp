#include <iostream>
#include <string>


using std::string;
using std::cout;
using std::endl;


void stringDoubler(string in) {

    in.append(in);

}

int main (void) {

    string hello("Hello, world!");

    cout << "Our original string is: " << hello << endl;

    stringDoubler(hello);

    cout << "After doubling, our string is: " << hello << endl;

    cout << "But, if we make a copy of it and double it locally...: ";

    string hello2 = hello;

    hello2.append(hello);

    cout << hello2 << endl;


    // another thing that's jarring
    // in Java, `string hello2 = hello` would create _another reference_
    // to the same object
    // here, this creates a _copy_ of the original object, and stores
    // it in the new variable

    // let's see that our original string was unchanged
    cout << "Original string, not modified: " << hello << endl;

    return 0;


}
