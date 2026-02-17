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


    /// second thought - malloc a big block of memory, index into it twice
    int rows = 3;
    int cols = 5;

    int * numbers2D = (int *)
        malloc (rows * cols * sizeof(int));


    // dynamicArrays.c: In function ‘main’:
    // dynamicArrays.c:30:17: error: subscripted value is neither array nor pointer nor vector
    //    30 |     numbers2D[0][0] = 1;

//    numbers2D[0][0] = 1;
//    numbers2D[0][1] = 2;

    // and so on....


    // third idea -- we know that when you use a normal 2D array,
    // everything is laid out sequentially in memory
    // the compiler just calculates an offset into the block of memory
    // based on the row & column specified
    // so, can _we_ do that ourselves?

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // idx = rowNo * cols + colNo
            int loc = i * cols + j;
            numbers2D[loc] = 10 * i + j;
        }
    }

    // yes, we can, but it's not beautiful -- obscures the fact that it's a 2D array
    // and it's easier to misuse

    printf("numbers[0][0] = %d\n", numbers2D[0]);
    printf("numbers[0][1] = %d\n", numbers2D[1]);
    printf("numbers[1][0] = %d\n", numbers2D[5]);
    printf("numbers[2][3] = %d\n", numbers2D[13]);


    // always a good idea! :)
    free(numbers2D);

    // fourth approach for a dynamic 2D array


    // since a 2D array is basically just an array-of-arrays,
    // let's simulate that behaviour.  We'll allocate each row separately
    // and then keep track of all of the rows that make up the array


    // note that we're using sizeof (int *) rather than sizeof(int)
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


    printf("Address of the outer array: myArr: %p\n", myArr);

    printf("\n");

    printf("Address of the pointer to the first row in the array: &myArr[0]: %p\n", &myArr[0]);
    printf("Address of the pointer to the second row in the array: &myArr[1]: %p\n", &myArr[1]);
    printf("Address of the pointer to the third row in the array: &myArr[2]: %p\n", &myArr[2]);

    printf("\n");

    printf("Address of the start of the first row of the array: myArr[0]: %p\n", myArr[0]);
    printf("Address of the start of the second row of the array: myArr[1]: %p\n", myArr[1]);
    printf("Address of the start of the third row of the array: myArr[2]: %p\n", myArr[2]);

    printf("\n");

    printf("Address of element [0][0]: &myArr[0][0]: %p\n", &myArr[0][0]);
    printf("Address of element [0][1]: &myArr[0][1]: %p\n", &myArr[0][1]);



    // when we're done, we've got to clean up in two steps, the reverse of the above

    for (int i = 0; i < rows; i++) {
        // now, clear the space of each individual row
        free(myArr[i]);
    }

    free(myArr);

    return 0;
}
