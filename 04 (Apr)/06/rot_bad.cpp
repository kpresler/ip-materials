#include <iostream>


using std::cout;
using std::endl;

class Demo {

    public:
        Demo(int num) {
            this -> num = new int;
            *(this->num) = num;
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
