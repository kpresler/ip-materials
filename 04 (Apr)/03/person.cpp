#include "person.hpp" // quotes for our headers
#include <algorithm>
#include <sstream>

using std::string;
using std::ostringstream;
using std::istringstream;

// note that our Person now has first names, and last names, stored separately

Person::Person(string first, string last) {
    this -> firstName = first;
    this -> lastName = last;
}

Person::Person(string name) {
    istringstream iss(name);

    // not going to work well if they have a middle name, but you get the idea
    iss >> firstName;
    iss >> lastName;

}

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

string Person::toString() const {
    ostringstream oss;
    oss << firstName << " " << lastName << " is friends with [";

    for (int i = 0; i < (int) friends.size(); i++) {
        oss << friends.at(i).firstName << " " << friends.at(i).lastName;

        if (i + 1 < (int) friends.size()) oss << ", ";
    }

    oss << "]";

    return oss.str();

}
