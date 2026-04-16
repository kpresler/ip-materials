#include <iostream>

using std::cout;
using std::endl;

int main (void) {


    enum class State {AL, AZ, AK, AR, CA, CO, CT, MD, NC, NV, WV, WY};

    State st = State::NV;


    switch(st) {

        case State::AL: cout << "Really, Alabama?  No thanks.... " << endl; break;

        case State::AZ: cout << "The Grand Canyon sounds cool" << endl; break;

        case State::AK: cout << "Great place if you like the cold, or like moose.  And even better if you like both!" << endl; break;

        case State::MD: cout << "Obviously, the best!" << endl; break;

        case State::NC: cout << "Nice place, as long as you're not there in the summer." << endl; break;

        case State::NV: cout << "If you'd like to see the Eiffel Tower without stepping foot in France, this is your place" << endl; break;

        case State::WV: cout << "Beautiful place, but hopefully you enjoy being unemployed, or digging coal" << endl; break;

    }

    return 0;

}
