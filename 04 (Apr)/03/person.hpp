#include <string>
#include <vector>
#include <ostream>

#ifndef PERSON_H
#define PERSON_H

class Person {

    private:
        std::string firstName;
        std::string lastName;
        std::vector<Person> friends;

    public:
        Person(std::string name);

        Person(std::string first, std::string last);

        bool addFriend(Person & other);

        std::string toString() const;

        // now, you should understand what this is doing :)
        bool operator==(const Person & other) const {
            return other.firstName == this -> firstName && other.lastName == this -> lastName;
        }

        // friend std::ostream & operator<<(std::ostream & strm, const Person & person);

}; // like with structs, required


#endif
