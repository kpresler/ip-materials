#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int * numbers = (int *) malloc (10 * sizeof(int));


    printf("Base address is %p\n", numbers);

    int * numbers0 = numbers;
    int * numbers1 = numbers+1;
    int * numbers2 = numbers+2;

    printf("0 = %p\n", numbers0);
    printf("1 = %p\n", numbers1);
    printf("2 = %p\n", numbers2);

    *numbers0 = 0;
    *numbers1 = 10;
    *numbers2 = 20;

    printf("Looping through with pointer arithmetic\n");
    for (int i = 0; i < 3; i++) {
        printf("Value at index %d (%p) is %d\n", i, (numbers + i), *(numbers+i));

    }

    // note that we're using the block of memory we created above a lot like an array,
    // storing elements sequentially in a large block of memory

    // we can also use array syntax for accessing elements within it

    printf("Looping through with array indexing\n");
    for (int i = 0; i < 3; i++) {
        printf("Value at index %d (%p) is %d\n", i, &numbers[i], numbers[i]);
    }

    // another neat (?) trick -- you can index into an array backwards!
    printf("Looping through with backwards indexing\n");
    for (int i = 0; i < 3; i++) {
        printf("Value at index %d (%p) is %d\n", i, &i[numbers], i[numbers]);
    }

    free(numbers);

    return 0;
}
