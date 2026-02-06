#include <stdio.h>


void array_insert(int arr[], int len, int pos, int val);


int main (void) {


    int arr[10];

    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }


    printf("Original array\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }


    array_insert(arr, 5, 2, 100);


    printf("Updated array\n");
    for (int i = 0; i < 6; i++) {
        printf("%d\n", arr[i]);
    }

}




// assumes that `arr` has enough space to accommodate the new element
void array_insert(int arr[], int len, int pos, int val) {

    // basic idea -- we want to insert `val` at `pos`.  In order to
    // do so, we need to shift over all other elements to make space
    for (int i = pos; i < len; i++){
        arr[i+1] = arr[i];
    }
    arr[pos] = val;


}
