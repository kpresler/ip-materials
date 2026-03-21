#include <utility>
#include <string>
#include <tuple>
#include <cstdio>

using std::tuple;
using std::make_tuple;
using std::pair;
using std::make_pair;
using std::string;


void printCityLocation(tuple<string, float, float> city) {
    printf("%s is located at (%.2lf, %.2lf)\n", std::get<0>(city).c_str(), std::get<1>(city), std::get<2>(city));
}


int main (void) {

    // this is the same `pair` we used a moment ago, when working with maps
    // you can use them outside of maps, as well, if you want to bundle together two pieces of data
    // pair, and make_pair come from the utility header
    pair<int, int> topLeftP = make_pair(500, 200);

    printf("Coordinate located at (%d, %d)\n", topLeftP.first, topLeftP.second);


    // a tuple represents a generalisation of a pair.  You can have a 2-tuple, which is effectively the same
    // as a pair, or a 3-tuple, 4-tupe, etc.  tuples are created using make_tuple.
    tuple<string, float, float> ralLoc = make_tuple("Raleigh, NC", 35.78, -78.64);

    tuple<string, float, float> balLoc = make_tuple("Baltimore, MD", 39.29, -76.61);

    printCityLocation(ralLoc);
    printCityLocation(balLoc);

    tuple<int, int> topLeft = make_tuple(500, 200);

    // bizarre syntax for accessing things from a tuple.  who came up with this crap?    
    printf("Coordinate located at (%d, %d)\n", std::get<0>(topLeft), std::get<1>(topLeft));
    
    // Bjarne, would it have been too hard to do topLeft.get(0) instead?  apparently.
    
    return 0;
}
