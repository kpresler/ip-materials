#include <iostream>
#include <string>
#include <ostream>
#include "person.hpp"


using std::cout;
using std::endl;
using std::string;
using std::ostream;


/*
ostream & operator<<(ostream & strm, const Person & person) {
    strm << person.firstName << " " << person.lastName << " is friends with [";

    for (int i = 0; i < (int) person.friends.size(); i++) {
        strm << person.friends.at(i).firstName << " " << person.friends.at(i).lastName;

        if (i + 1 < (int) person.friends.size()) strm << ", ";
    }

    strm << "]";

    return strm;
}

*/

int main (void) {
    Person adam ("Adam J.");

    Person bob ("Bob S.");

    Person jane ("Jane", "M.");

    Person cave ("Cave", "J.");

    cave.addFriend(jane);
    cave.addFriend(adam);
    cave.addFriend(bob);

    cout << cave.toString() << endl;


    // does not work -- yet!
    cout << cave << endl;


    return 0;
}
