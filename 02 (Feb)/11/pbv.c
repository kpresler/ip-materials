#include <stdio.h>


void increment (int a);

// basic example showing how pass-by-value works

int main (void) {


    int x = 10;

    printf("x = %d\n", x);

    increment(x);

    printf("After incrementing; x = %d\n", x);

    return 0;

}


void increment (int a) {
    a += 1;
}
