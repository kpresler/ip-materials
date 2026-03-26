#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>
#include <cctype>

using std::string;
using std::stringstream;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;


bool is_vowel(char c) {
  const string VOWELS = "aeiou";
  return VOWELS.find(tolower(c)) != string::npos;
}

string abbreviate(const string &word) {
  string result;

  bool last_was_vowel = false;
  for (size_t i = 0; i < word.size(); i++) {
    bool cur_is_vowel = is_vowel(word[i]);

    if (cur_is_vowel) {
      if (!last_was_vowel) {
        result += '\'';
      }
    }
    else {
      result += word[i];
    }

    last_was_vowel = cur_is_vowel;
  }

  return result;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    cerr << "Usage: abbrev <infile> <outfile>" << endl;
    return 1;
  }

  ifstream in(argv[1]);
  if (!in.is_open()) {
    cerr << "Couldn't open input file" << endl;
    return 1;
  }

  ofstream out(argv[2]);

  string line;
  while (getline(in, line)) {
    string word;
    stringstream ss(line);

    bool first = true;

    while (ss >> word) {
      if (first) {
        first = false;
      } else {
        out << " ";
      }

      word = abbreviate(word);
      out << word;
    }

     out << endl;
  }

  return 0;
}
