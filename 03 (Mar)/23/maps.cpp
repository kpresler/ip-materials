#include <map>
#include <string>
#include <iostream>
#include <utility>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::pair;


int main (void) {
    map<string, string> cities;

    cities["Maryland"] = "Baltimore";
    cities["North Carolina"] = "Charlotte";
    cities["Massachusetts"] = "Boston";
    cities["New York"] = "New York";

    string key("Maryland");

    cout << "The largest city in " << key << " is " << cities[key] << endl;

    key = "North Carolina";

    cout << "The largest city in " << key << " is " << cities[key] << endl;

    key = "South Carolina";

    cout << "The largest city in " << key << " is " << cities[key] << endl;





    cout << "Map contains an entry for " << key << ": " << ((cities.find(key) != cities.end()) ? "true" : "false") << endl;

    key = "North Dakota";

    cout << "Map contains an entry for " << key << ": " << ((cities.find(key) != cities.end()) ? "true" : "false") << endl;




    cout << string(20, '~') << endl;

    for (map<string, string>::iterator it = cities.begin(); it != cities.end(); ++it) {

        pair<string, string> entry = *it;

        cout << "The largest city in " << entry.first << " is " << entry.second << endl;

        // or, alternatively, 
        cout << "The largest city in " << it -> first << " is " << it -> second << endl;


    }

    return 0;
}
