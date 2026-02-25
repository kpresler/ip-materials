#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node_ {
    int data;  // any type we want is fine, including a struct

    // a reference to the next node in our list
    // this must use the `struct Node_ *` because the typedef'd alias doesn't exist yet
    struct Node_ * next;

} Node;


Node * newNode(int data, Node * next){

    Node * new = malloc(sizeof(Node));
    new -> data = data;
    new -> next = next;

    return new;

}

Node * addAtEnd(int data, Node * head){

    // make sure that we were given a pointer to an existing list that we can update
    assert(head);


    // find the end of the chain of nodes, so that we can add our new node at the end
    Node * temp = head;

    // why do I loop until temp.next is null, instead of looping until temp is null?
    while (temp -> next) {
        temp = temp -> next;
    }

    // create a new node & fill it in
    Node * new = malloc(sizeof(Node));
    new -> data = data;
    new -> next = NULL;

    // and then link it to our list
    temp -> next = new;


}

void printList(Node * head) {

    Node * current = head;

    while (current) {
        printf("%d", current -> data);
        if (current -> next) printf(" -> ");

        current = current -> next;
    }
    printf("\n");


}

int main (void) {


    // this is possibly the simplest way to build a List
    // although, as we can see, it's not very elegant to do it like this.
    Node * head;
    head = malloc(sizeof(Node));
    head -> data = 100;
    head -> next = malloc(sizeof(Node));
    head -> next -> data = 200;
    head -> next -> next = NULL;

    printf("First list, built by hand\n");
    printList(head);


    // we can instead use a helper function to assist with the task
    head = newNode(10, NULL);

    head = newNode(20, head);

    head = newNode(30, head);

    // let's think, carefully, about what we've just built here
    // is it what we want?  not entire clear.

    printf("Second list, built with the newNode function\n");
    printList(head);

    // start off a list
    head = malloc(sizeof(Node));
    head -> data = 1;
    head -> next = NULL;

    // and then use our function to build out the rest of it
    addAtEnd(2, head);
    addAtEnd(3, head);
    addAtEnd(4, head);
    addAtEnd(5, head);

    printf("Third list, built with the addAtEnd function\n");
    printList(head);

}
