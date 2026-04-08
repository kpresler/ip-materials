#include <iostream>

template<typename T>
class ArrayList {

    private:
        T * data;
        int numElements;
        int capacity;

        void ensureCapacity() {
            if (numElements == capacity) {
                T * newSpace = new T[capacity*2];
                for (int i = 0; i < capacity; i++) {
                    newSpace[i] = data[i];
                }
                delete[] data;
                data = newSpace;
                capacity *= 2;
            }

        }

    public:
        ArrayList(int size) {
            this -> numElements = 0;
            this -> data = new T[size];
            this -> capacity = size;
        }

        ~ArrayList() {
            delete[] data;
        }

        /* we should have a copy constructor and operator= defined here too */

        void add(T t) {
            ensureCapacity();
            data[numElements++] = t;

        }

        int size(){
            return numElements;
        }

        T & operator[](const int & idx) {
            if (idx < 0 || idx >= numElements) throw "Invalid index!";
            return data[idx];
        }

};

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


    ArrayList<double> ald(5);
    
    ald.add(20.7);
    ald.add(-13.2);
    ald.add(46/3);

    for (int i = 0; i < ald.size(); i++) {
        cout << ald[i] << endl;
    }
}
