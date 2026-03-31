#include <iostream>
#include <string>
#include "person.hpp"


using std::cout;
using std::endl;
using std::string;
using std::vector;



int main (void) {


    Person nancy ("Nancy O.");
    Person adam ("Adam J.");
    Person bob ("Bob S.");


    cout << adam.toString() << endl;
    cout << bob.toString() << endl;

    bob.addFriend(nancy);

    cout << bob.toString() << endl;




    // a brief note about value semantics, and default constructors
    // In Java (/Python) , it's easy to have "null" objects (Python
    // uses `None`, but it's the same idea).  In C++, unless you
    // use C-style pointers, you can never have a null object.
    // this means that if you declare an array of a type,
    // rather than a bunch of empty ("unfilled") slots, like in
    // a Java array, you instead get a bunch of empty objects
    // an "empty object" is one where the compiler calls the default
    // constructor -- so you get things like an empty string, an empty
    // vector, etc.

    // if your type doesn't have a default constructor
    // then you can't create an empty array of that type
//    Person people[10];

    // also applies to heap-allocated with `new`
//    Person * people = new Person[10];


    // the question then becomes -- should you always have a default constructor?
    // I would argue, "Probably not".  Part of the job of a constructor is to
    // collect the arguments necessary to assemble an object of that type.
    // IMO, having objects that exist, but are not properly initialised
    // is not a nice state for your program to be in

    // then, what can you do?

    // if you create a STL container (vector, etc) with an initially empty
    // capacity, this works.  You can then then add your elements later


    vector<Person> people;

    people.push_back(Person("Abraham Lincoln"));
    people.push_back(Person("Teddy Roosevelt"));


    // there are also horrible hacks: https://stackoverflow.com/a/64913007

    return 0;
}
