#include <iostream>
#include "ArrayList.hpp"

using std::cout;
using std::endl;


int main (void) {

    ArrayList<int> al(2);

    al.add(1);
    al.add(2);
    al.add(3);
    al.add(4);

    for (int i = 0; i < al.size(); i++) {
        cout << al[i] << endl;
    }



}
