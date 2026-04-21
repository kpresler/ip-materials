#include <iostream>

class ArrayList {

    private:
        int * data;
        int numElements;
        int capacity;

        void ensureCapacity() {
            if (numElements == capacity) {
                int * newSpace = new int[capacity*2];
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
            this -> data = new int[size];
            this -> capacity = size;
        }

        class iterator {

            int idx;

            int * data;

            public:

                iterator(int idx, int * data) {
                    this -> idx = idx;
                    this -> data = data;
                }

                iterator & operator++ () {
                    idx++;
                    return *this;
                }

                bool operator!= (const iterator & other) const {
                    return data != other.data || idx != other.idx;
                }

                int & operator* () {
                    return data[idx];
                }

        };

        iterator begin() {
            return iterator(0, data);
        }

        iterator end() {
            return iterator(numElements, data);
        }

        ~ArrayList() {
            delete[] data;
        }

        /* we should have a copy constructor and operator= defined here too */

        void add(int t) {
            ensureCapacity();
            data[numElements++] = t;

        }

        int size(){
            return numElements;
        }

        int & operator[](const int & idx) {
            if (idx < 0 || idx >= numElements) throw "Invalid index!";
            return data[idx];
        }

};

using std::cout;
using std::endl;


int main (void) {

    ArrayList al(2);

    al.add(1);
    al.add(2);
    al.add(3);
    al.add(4);

    cout << "Printing using a counted for loop:" << endl;
    for (int i = 0; i < al.size(); i++) {
        cout << al[i] << endl;
    }


    cout << endl << "Printing using an iterator:" << endl;
    for (ArrayList::iterator it = al.begin(); it != al.end(); ++it) {
        cout << *it << endl;
    }



}
