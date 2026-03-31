#include "person.hpp" // quotes for our headers
#include <algorithm>
#include <sstream>

using std::string;
using std::ostringstream;

// this is what we learned last class
//Person::Person(string name) : name(name) {}

// we've got another way to write constructors as well
// here, we do all of the initialisation within the body of the constructor, Java-style
// if you want to have the paramater have the same name as the class field (a good practice)
// you then run into a name collision.  we saw this with variable shadowing previously
// However, we've got a solution: `this`


Person::Person(string name) {
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
