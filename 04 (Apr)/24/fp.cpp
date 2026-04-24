#include <iostream>
#include <vector>
#include <string>


using std::vector;
using std::string;
using std::cout;
using std::endl;


vector<string> allToTitle(vector<string> & strings) {

    vector<string> res;

    for (string s : strings) {

        string transformed;

        transformed.push_back(std::toupper(s.at(0)));

        for (int i = 1; i < s.size(); i++) {
            transformed.push_back(std::tolower(s.at(i)));
        }

        res.push_back(transformed);

    }

    return res;

}


vector<int> allDoubled(vector<int> & numbers) {

    vector<int> res;

    for (int & num : numbers) {

        res.push_back(num * 2);

    }

    return res;

}

template<typename T>
vector<T> map(vector<T> things, T (* transform) (const T& orig) ){

    vector<T> res;

    for (T & t : things) {
        res.push_back( transform(t) );

    }

    return res;

}

int doubleInt(const int & orig) {return orig * 2;}



int main (void) {


    vector<string> fruits = {"apple", "bANANA", "GRAPE", "Orange", "manGO" };

    vector<string> titled = allToTitle(fruits);

    for (string & s : titled) cout << s << endl;


    // I can very readily perform the same operation on a different set of data
    // this is, after all, the point of why we write functions in the first place

    cout << endl << "~~~" << endl << endl;

    vector<string> animals = {"cOw", "aardvark", "goat", "sheep", "HORSE", "antelope"};

    titled = allToTitle(animals);

    for (string & s : titled) cout << s << endl;


    vector<int> pows = {2,4,8,16,32,64,128,256,512,1024};

    vector<int> res = allDoubled(pows);

    res = map(pows, doubleInt);

    for (int & i : res) cout << i << " ";

    cout << endl;

    return 0;

}
