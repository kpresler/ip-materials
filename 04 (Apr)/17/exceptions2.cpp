#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

#include "pstream.h"

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;


class ExecException : public std::runtime_error {

    public:
        ExecException (string msg) : std::runtime_error(msg) {

        }

};

string exec(const char * cmd);

int main (void) {

    string cmd;

    cout << "Enter a command to run: " << endl;

    cin >> cmd;

    try {
        string result = exec(cmd.c_str());

        cout << "Results of running command" << endl << "~~~~" << endl << result << endl;

    }
    catch (ExecException & ee) {
        cerr << "Error occurred: " << ee.what() << endl;
    }

}



string exec(const char * cmd) {
  redi::ipstream proc(cmd, redi::pstreams::pstdout | redi::pstreams::pstderr);
  std::string line;
  // read child's stdout

  string result;

  while (std::getline(proc.out(), line))
    result += line += '\n';

  // if reading stdout stopped at EOF then reset the state:
  if (proc.eof() && proc.fail())
    proc.clear();
  // read child's stderr
  if (std::getline(proc.err(), line))
    throw ExecException("Could not execute command `" + string(cmd) + "`");

  return result;
}

