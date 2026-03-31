#include "person.hpp" // quotes for our headers
#include <algorithm>
#include <sstream>

using std::string;
using std::ostringstream;

Person::Person(string name) {
    this -> name = new string(name);
}


Person::~Person(){
    delete this -> name;
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
    oss << *name << " is friends with [";

    for (int i = 0; i < (int) friends.size(); i++) {
        oss << *(friends.at(i).name);

        if (i + 1 < (int) friends.size()) oss << ", ";
    }

    oss << "]";

    return oss.str();

}
