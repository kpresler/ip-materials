#include <iostream>
#include <string>
#include "person.hpp"


using std::cout;
using std::endl;
using std::string;



int main (void) {

    // create a couple of objects, by calling the Person constructor
    // note, no need for the `new` keyword here

    // if we _did_ use `new`, that would heap-allocate them
    // with all of the fun (?) that comes from that

    Person nancy ("Nancy O.");

    Person adam ("Adam J.");

    Person bob ("Bob S.");


    // toString our objects to that we can print them out
    // the more C++-styled approach here would be overloading
    // the << operator, which we'll learn later
    cout << nancy.toString() << endl;

    adam.addFriend(bob);

    cout << adam.toString() << endl;
    cout << bob.toString() << endl;

    bob.addFriend(nancy);

    cout << bob.toString() << endl;


    // let's see what const does with objects


    // our cloned version of Nancy is const
    // this means that we can call const methods
    // on her, but we cannot call non-const methods
    const Person nancysClone = nancy;

    cout << nancysClone.toString() << endl; // this is acceptable

    //nancysClone.addFriend(adam); // illegal -- can't call a non-const method on a const object


    return 0;
}
