#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int * primes(int upperLimit, int *found);

bool isPrime(int num);

int main (void) {


    int a = 10;
    char c = 'J';

    char arr[] = "JHU";


    char * arrHeap = (char *) malloc(sizeof(arr)); /* no need for +1, since sizeof includes null terminator */
    strcpy(arrHeap, arr);



    printf("stack-allocated `a` is located at   %p\n", &a);
    printf("stack-allocated `c` is located at   %p\n", &c);
    printf("stack-allocated `arr` is located at %p\n", arr);
    printf("heap-allocated `arrHeap` is located at %p\n", arrHeap);


    free(arrHeap); // make sure to free all heap-allocated memory when we are done with it;


    int upperLimit = 2000;
    int primesFound = 0;

    int * res = primes(upperLimit, &primesFound);
	
    if (! res) return -1;

    printf("Found %d primes between 0 and %d\n", primesFound, upperLimit);

    for (int i = 0; i < primesFound; ) {
        printf("%4d ", res[i]);
        if (++i % 10 == 0) printf("\n");

    }
    printf("\n");

    return 0;

}


int * primes(int upperLimit, int *found) {

    // clear out the `found` variable, in case there was junk, since we've not found anything yet
    *found = 0;


    // we will never find any more primes than the number we're considering
    // might as well use calloc so that it zeroes things out
    int * primesFound = calloc(upperLimit, sizeof(int));

    if (! primesFound) return NULL; // should never fail on a modern system with a virtual memory system, but good practice

    // edge cases
    if (upperLimit >= 1) primesFound[(*found)++] = 1;
    if (upperLimit >= 2) primesFound[(*found)++] = 2;

    // main loop over all numbers to consider
    for (int i = 3; i < upperLimit; i += 2) {

        // we've seen that C treats pointers and arrays extremely similarly
        // as a result, we can index into a block of memory pointed-to by a
        // pointer in the same way that we would a block of memory that is
        // an array
        if (isPrime(i)) primesFound[(*found)++] = i;

    }

    // this is not really required, but it will shrink the block of memory down to 
    // fit the number of primes we actually found, which is obviously less than we originally allocated
    // realloc _should_ never give us a new pointers, since it should always be able to shrink
    // our block (is the reverse guaranteed to be true?), but if we don't reassign, gcc complains

    primesFound = realloc(primesFound, *found * sizeof(int));

    return primesFound;

}


// simple trial division check.  Sieve of Eratosthenes would be better
bool isPrime(int num){
    for (int i = 2; i < num; i++){
        if (num % i == 0) return false;
    }
    return true;

}
