#include <iostream>
#include <string>
#include "person.hpp"


using std::cout;
using std::endl;
using std::string;



int main (void) {


    Person nancy ("Nancy O.");
    Person adam ("Adam J.");
    Person bob ("Bob S.");


    cout << adam.toString() << endl;
    cout << bob.toString() << endl;

    bob.addFriend(nancy);

    cout << bob.toString() << endl;


    Person cave;

    cave.addFriend(bob);

    cout << cave.toString() << endl;


    return 0;
}
