#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main (void) {

    int * num = new int;

    *num = 200;

    cout << "Number is " << *num << " and is located at " << num << endl;

    // things allocated with `new` get deallocated with `delete`.
    delete num;

    // makes space for 20 ints
    // no need to calculate space manually like we did for malloc
    int * nums = new int[20];

    for (int i = 0; i < 20; i++) {
        nums[i] = i;
    }

    cout << "nums[3] == " << nums[3] << endl;

    // if you allocate with `new []`, you must deallocate with `delete[]`
    delete[] nums;


    // this is nice -- if the thing you're allocating is an object
    // the constructor gets called as part of the `new` operation`
    // by default, it would call the default constructor, but you can 
    // provide arguments if you wish
    string * str = new string("hello, world");

    cout << "String stores the value `" << *str << "`" << endl;
    
    delete str;

    return 0;
}
