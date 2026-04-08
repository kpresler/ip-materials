#include <iostream>
#include <string>
#include <vector>

using std::vector;


template<class T>
T findGreatest(vector<T> list) {
    if (list.size() == 0) throw "Empty list!";

    T greatest = list.at(0);

    for (int i = 1; i < list.size(); i++ ) {

        T candidate = list.at(i);
        if (candidate > greatest) greatest = candidate;

    }

    return greatest;

}

template<typename T>
T sumList(vector<T> list, T identity) {

    T sum = identity;

    for (typename vector<T>::iterator it = list.begin(); it != list.end(); it++) {
        sum += *it;
    }

    return sum;

}


using std::cout;
using std::endl;
using std::string;


int main (void) {

    vector<int> ints = {1,2,3,4,5};
    vector<string> strings = {"mango", "banana", "grape", "apple", "cherry"};


    cout << "Greatest element in list of ints: " << findGreatest(ints) << endl;
    cout << "Greatest element in list of strings: " << findGreatest(strings) << endl;


    cout << "Sum of all ints: " << sumList(ints, 0) << endl;


    string id = "";
    cout << "Concatenation of all strings: " << sumList(strings, id) << endl;



    return 0;
}
