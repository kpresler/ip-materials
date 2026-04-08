#include "ArrayList.hpp"


template<typename T>
void ArrayList<T>::ensureCapacity() {
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

template<typename T>
ArrayList<T>::ArrayList(int size) {
    this -> numElements = 0;
    this -> data = new T[size];
    this -> capacity = size;
}


template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template<typename T>
void ArrayList<T>::add(T t) {
    ensureCapacity();
    data[numElements++] = t;
}

template<typename T>
int ArrayList<T>::size(){
    return numElements;
}

template<typename T>
T & ArrayList<T>::operator[](const int & idx) {
    if (idx < 0 || idx >= numElements) throw "Invalid index!";
    return data[idx];
}
