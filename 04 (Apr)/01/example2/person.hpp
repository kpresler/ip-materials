#include <string>
#include <vector>

#ifndef PERSON_H
#define PERSON_H

class Person {

    private:
        std::string name;
        std::vector<Person> friends;

    public:

        // C++ also supports _default arguments_ with a syntax essentially the same as in Python
        // since this can't b ehandled elegantly at runtime like Python would do, the compiler
        // handles it by creating two different constructors -- one of which has a parameter, and
        // one of which doesn't, and sets the value from a string literal

        Person(std::string name = "Cave Johnson");

        void setName(std::string name);

        bool addFriend(Person & other);

        // `const` means that this method promises it will not modify the underlying object
        // you can only call const methods on objects that are const
        std::string toString() const;

        /* you can ignore this part */
        bool operator==(const Person & other) const {
            return other.name == this -> name;
        }

}; // like with structs, required


#endif
