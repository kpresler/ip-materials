#include <iostream>


template<typename T>
struct Node {

    T data;
    Node * next;
};

template<typename T>
int length(Node<T> * list){
    int len = 0;
    for (Node<T> * current = list ; current; ++len, current = current->next);

    return len;
}


int main (void) {
    Node<int> n1 = {10, NULL};
    Node<int> n2 = {20, &n1};
    Node<int> n3 = {30, &n2};


    // error: providing a float where an int was expected
    //Node<int> n4 = {3.5, &n3};

    // error: providing a string where an int was expected
    //Node<int> n4 = {"hello", &n3};

    using std::cout; using std::endl;

    cout << "Length of our list is " << length(&n3) << endl;
	
	
	Node<char> c1 = {'A', NULL};
	Node<char> c2 = {'B', &c1};
	Node<char> c3 = {'C', &c2};
	Node<char> c4 = {'D', &c3};
	
	
    cout << "Length of our list is " << length(&c4) << endl;

    return 0;
}
