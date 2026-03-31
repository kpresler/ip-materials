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


    bob.addFriend(adam);

    cout << adam.toString() << endl;
    cout << bob.toString() << endl;

    bob.addFriend(nancy);

    cout << bob.toString() << endl;


    return 0;
}
