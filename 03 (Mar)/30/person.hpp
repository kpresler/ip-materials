#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person {

    private:
        std::string name;
        std::vector<Person> friends;

    public:
        Person(std::string name);

        bool addFriend(Person & other);

        // `const` means that this method promises it will not modify the underlying object
        // you can only call const methods on objects that are const
        std::string toString() const;

        /* you can ignore this part, we'll get to it on Friday */
        bool operator==(const Person & other) const {
            return other.name == this -> name;
        }

}; // like with structs, required


#endif
