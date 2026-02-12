#include <stdio.h>
#include <stdlib.h>



int main (void) {


    int numbers[] = {2, 4, 8, 16};

    // invalid array bounds
    // due to how memory is laid out, for the first index (-1) we actually
    // get the value stored in `i` itself.  hmm.
    // unfortunately, Valgrind can't warn us about that, since we are using
    // a memory location that _is_ perfectly legal for our function
    // but, it'll warn us when we wander off the end
    for (int i = -1; i < 6; i++)
        printf("Value in %p is %d\n", (numbers + i), numbers[i]);


    int x;

    if (x) printf ("x is nonzero\n");
    else printf("x is zero\n");


    int * arr = malloc(100 * sizeof(int));

    // other stuff


    // need more space
    arr = malloc (1000 * sizeof(int));


    // make sure to free when we're done
    free(arr);
    free(arr); // oops

    return 0;

}
