#include "person.hpp" // quotes for our headers
#include <algorithm>
#include <sstream>

using std::string;
using std::ostringstream;




// C++ also supports _default arguments_ with a syntax essentially the same as in Python
// since this can't b ehandled elegantly at runtime like Python would do, the compiler
// handles it by creating two different constructors -- one of which has a parameter, and
// one of which doesn't, and sets the value from a string literal

// NOTE that the compiler only wants you to put the default value within the header file
// I like to put it, commented out, within my constructor (or other method where I'm using this)
// to remind myself that I've got a default value, and what it is
// if it is _not_ commented out here, the compiler will be very displeased :)

Person::Person(string name /* = "Cave Johnson" */) {
    this -> name = name;
}


void Person::setName(string name){
    // and, likewise
    this -> name = name;
}


// a normal, non-constructor method
// `other` comes in as a ref so that we can modify the other object
bool Person::addFriend(Person & other) {

    if(std::find(friends.begin(), friends.end(), other) != friends.end()) {
        return false; // `this` already friends with `other`
    }

    else {
        friends.push_back(other);
        other.friends.push_back(*this);
        return true;
    }

}

// a const method
string Person::toString() const {
    ostringstream oss;
    oss << name << " is friends with [";

    for (int i = 0; i < (int) friends.size(); i++) {
        oss << friends.at(i).name;

        if (i + 1 < (int) friends.size()) oss << ", ";
    }

    oss << "]";

    return oss.str();

}
