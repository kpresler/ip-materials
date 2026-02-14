#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int * numbers = (int *) malloc (10 * sizeof(int));


    printf("Base address is %p\n", numbers);


    // first thought -- can we get an array to point to this block of memory, like with another pointer?
    // no!
    // dynamicArrays.c: In function ‘main’:
    // dynamicArrays.c:14:26: error: invalid initializer
    //    14 |     int numbersArr[10] = numbers;
    //       |

//    int numbersArr[10] = numbers;

    int rows = 3;
    int cols = 5;

    int * numbers2D = (int *)
        malloc (rows * cols * sizeof(int));


//    numbers2D[0][0] = 1;
//    numbers2D[0][1] = 2;

    // and so on....


    // still got a chunk of memory from above

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int loc = i * cols + j;
            numbers2D[loc] = 10 * i + j;
        }
    }


    printf("numbers[0][0] = %d\n", numbers2D[0]);
    printf("numbers[0][1] = %d\n", numbers2D[1]);
    printf("numbers[1][0] = %d\n", numbers2D[5]);
    printf("numbers[2][3] = %d\n", numbers2D[13]);


    // always a good idea! :)
    free(numbers2D);

    // fourth approach for a dynamic 2D array
    // not that we're using sizeof (int *) rather than sizeof(int)

    // myArr is going to store "pointer-to-int"s instead of ints
    // so we need to know how big the pointers are
    int ** myArr = malloc(sizeof(int *) * rows);

    for (int i = 0; i < rows; i++) {
        // now, make the space for each individual row
        myArr[i] = malloc(sizeof(int) * cols);
    }


    myArr[0][0] = 0;
    myArr[0][1] = 1;
    /* ..... */
    myArr[2][4] = 24;


    // when we're done, we've got to clean up in two steps, the reverse of the above

    for (int i = 0; i < rows; i++) {
        // now, clear the space of each individual row
        free(myArr[i]);
    }

    free(myArr);

    return 0;
}
