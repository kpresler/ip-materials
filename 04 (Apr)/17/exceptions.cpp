#include <vector>
#include <iostream>
#include <string>


using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main (void) {


    vector<int> nums = {1,2,3,4,5};

    // wanders off the edge of the map -- bang!
    for (int i = 0; i < 6; i++) {
        cout << nums.at(i) << endl;

    }


    //  next example -- we (can) get an exception trying to parse a string as an int

    string in;

    cout << "Please enter a number: " << endl;
    cin >> in;

    try {

        int num = stoi(in);

        cout << "Your number was " << num << " and squared it is " << num*num << endl;

    }
    catch (std::invalid_argument & iae) {
        cout << "That wasn't a number!" << endl;
    }

}
