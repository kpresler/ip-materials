#include <string>
#include <vector>

#ifndef PERSON_H
#define PERSON_H

class Person {

    private:
        std::string * name;
        std::vector<Person> friends;

    public:
        Person(std::string name);

        // new -- dstructors!  same name as the constructor, but with a leading ~
        ~Person();

        void setName(std::string name);

        bool addFriend(Person & other);

        // `const` means that this method promises it will not modify the underlying object
        // you can only call const methods on objects that are const
        std::string toString() const;

        /* you can ignore this part */
        bool operator==(const Person & other) const {
            return *(other.name) == *(this -> name);
        }

}; // like with structs, required


#endif
