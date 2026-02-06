#include <stdio.h>


int array_mult(int arr[][4], int len, int factor);


int main (void) {

    int powers[][4] = {{2,4,8,16}, {3,9,27,81}};

    // might be tempting to tell compiler, "Figure out how big everything is" based on the initialisation
    // but that does not work :(
    // int powers[][] = {{2,4,8,16}, {3,9,27,81}};

    // same trick that we are familiar with from before about figuring out how many elements are in the array still works
    // sizeof (powers) is the size of the entire 2D array
    // sizeof (powers[0]) is the size of the first element of powers, which is the first inner array
    // since the entire 2D array is twice the size of its first element, this works fine

    for (int i = 0; i < sizeof(powers)/sizeof(powers[0]); i++ ) {

        int innerSize = sizeof(powers[0]) / sizeof(powers[0][0]);
        for (int j = 0; j < innerSize; j++ ) {
            printf("%2d", powers[i][j]);
            if (j != (innerSize -1)) printf(" ");

        }
        printf("\n");
    }

    array_mult(powers, 2, 3);

    printf("After multiplication:\n");

    for (int i = 0; i < sizeof(powers)/sizeof(powers[0]); i++ ) {

        int innerSize = sizeof(powers[0]) / sizeof(powers[0][0]);
        for (int j = 0; j < innerSize; j++ ) {
            printf("%2d", powers[i][j]);
            if (j != (innerSize -1)) printf(" ");

        }
        printf("\n");
    }

    return 0;
}


int array_mult(int arr[][4], int len, int factor){

    // like we saw previously...doing sizeof(arr) doesn't work, and instead gives us sizeof(int*) & a compiler warning
    for (int i = 0; i < len; i++ ) {
        // however, this _does_ work -- since the compiler does _really care_ about the size of the inner array
        // so that it can get things laid out properly in memory, it tracks enough information for this to work
        // however, since we had to declare the size in the function header anyways....why do it?

        int innerSize = sizeof(arr[0]) / sizeof(arr[0][0]); /* = 4; // would be better */
        for (int j = 0; j < innerSize; j++ ) {
            arr[i][j] *= factor;
        }
    }


}



