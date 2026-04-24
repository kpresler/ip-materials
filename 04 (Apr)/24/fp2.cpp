#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::vector;
using std::string;
using std::cout;
using std::endl;


template<typename T, typename T_transform>
vector<T> map(vector<T> things, T_transform transform ){

    vector<T> res;

    for (T & t : things) {
        res.push_back( transform(t) );

    }

    return res;

}

int doubleInt(const int & orig) {return orig * 2;}

string titleString(const string & s) {
    string transformed;

    transformed.push_back(std::toupper(s.at(0)));

    for (int i = 1; i < s.size(); i++) {
        transformed.push_back(std::tolower(s.at(i)));
    }

    return transformed;

}



int main (void) {

    vector<int> pows = {2,4,8,16,32,64,128,256,512,1024};

    vector<int> res = map(pows, doubleInt);

    for (int & i : res) cout << i << " ";

    cout << endl;


    vector<string> fruits = {"apple", "bANANA", "GRAPE", "Orange", "manGO" };

    vector<string> titled = map(fruits, titleString);


    for (string & s : titled) cout << s << endl;

    res = map(pows,
      [](const int & i){ return i * 2; }
    );


    std::sort(titled.begin(), titled.end()); // default behaviour -- sort in ascending order

    // still sorting in ascending order, but this time, we're explicitly passing a comparator that says
    // how to do that
    std::sort(titled.begin(), titled.end(), [](const string & first, const string & second){ return first < second; } );
    cout << "Ascending order: " << endl;
    for (string & s : titled) cout << s << endl;


    // now, sorting in descending order, by making a slight modification to our comparator
    std::sort(titled.begin(), titled.end(), [](const string & first, const string & second){ return first > second; } );
    cout << "Descending order: " << endl;
    for (string & s : titled) cout << s << endl;


    return 0;

}
