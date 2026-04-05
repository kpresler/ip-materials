#include <iostream>


using std::cout;
using std::endl;

class Demo {

    public:
        Demo(int num) {
            this -> num = new int;
            *(this -> num) = num;
        }

        Demo(const Demo & rhs) {
            this -> num = new int;
            *(this -> num) = *rhs.num;
        }

        Demo & operator=(const Demo & rhs) {
            // `this` will already have memory allocated
            // from when it was constructed.  so we can reuse it
            * (this -> num) = *rhs.num;
            return *this;
        }

        ~Demo(){
            delete num;
        }


    private:
        int * num;


};

int main (void) {

    Demo d1 (100);

    Demo d2 = d1;

    Demo d3 (d1);

    d3 = Demo(200);


}
