#include "person.hpp" // quotes for our headers
#include <algorithm>
#include <sstream>

using std::string;
using std::ostringstream;

// because we are implementing the methods outside of the class they are
// declared in, we have to do `ClassName::methodName` so that the compiler knows this is a method & not a function



// Constructor for our Person class
// constructors always have no return type, and have the
// same name as their class
// we'll learn another way to write the constructor next class that I think looks nicer
Person::Person(string name) : name(name) {

}


// a normal, non-constructor method
// `other` comes in as a ref so that we can modify the other object
bool Person::addFriend(Person & other) {

    // access data from the current object instance
    if(std::find(friends.begin(), friends.end(), other) != friends.end()) {
        return false; // `this` already friends with `other`
    }

    else {
        // modify the current object instance, and our parameter
        friends.push_back(other);
        other.friends.push_back(*this);
        return true;
    }

}

// a const method
// this signifies that the method will not (and in fact, cannot)
// modify the current object.
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
