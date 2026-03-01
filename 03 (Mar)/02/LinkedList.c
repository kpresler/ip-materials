#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node_ {
    int data;  // any type we want is fine, including a struct

    // a reference to the next node in our list
    // this must use the `struct Node_ *` because the typedef'd alias doesn't exist yet
    struct Node_ * next;

} Node;


void printList(Node * head) {

    Node * current = head;

    while (current) {
        printf("%d", current -> data);
        if (current -> next) printf(" -> ");

        current = current -> next;
    }
    printf("\n");


}

void insertFront(Node ** head, int val) {

    Node * newNode = malloc(sizeof(Node));
    newNode -> data = val;
    newNode -> next = *head;

    *head = newNode;


}

int main (void) {

    Node * head = NULL;
    insertFront(&head, 1000);
    insertFront(&head, 500);
    insertFront(&head, 250);

    printList(head);

}
