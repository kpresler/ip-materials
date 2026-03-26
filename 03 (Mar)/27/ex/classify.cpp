#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;

int main() {
  double sum_fp = 0.0;
  int sum_i = 0;
  int ntok = 0;
  int ntok_c = 0;

  string token;

  while (cin >> token) {
    double dval;
    int ival;
    bool hasInt = false;

    stringstream ss1(token);
    if (ss1 >> ival) {
      // token is an integer only if the entire token was matched
      string extra;
      if (!(ss1 >> extra)) {
        sum_i += ival;
        hasInt = true;
      }
    }
    // now try for double
    if (! hasInt) {
      stringstream ss2(token);
      if (ss2 >> dval) {
        sum_fp += dval;
      } else {  // not a number
        ntok++;
        ntok_c += (int)token.size();
      }
    }
  }

  cout << "Floating point sum: " << sum_fp << endl;
  cout << "Integer sum: " << sum_i << endl;
  cout << "Number of non-numeric tokens: " << ntok << endl;
  cout << "Number of characters in non-numeric tokens: " << ntok_c << endl;

  return 0;
}
