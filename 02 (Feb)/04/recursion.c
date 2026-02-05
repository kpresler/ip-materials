#include <stdio.h>


long factorial(int n) {

    // base case -- 0! or 1! is 1
    if (n <= 1) return 1;

    // recursive case -- I don't know how to answer the problem 
    // directly, so let's make it smaller
    return n * factorial (n - 1);

}


long fib(int n) {

    if (n<=0) return 0;

    if (n == 1 || n == 2) {
        return 1;
    }

    return fib(n-1) + fib(n-2);

}



int main (void) {

    printf("5! = %ld\n", factorial(5));


    printf("20! = %ld\n", factorial(20));


    for (int i = 1; i < 20; i++) {

        printf("fib(%d) = %ld\n", i, fib(i));

    }

    return 0;


}
