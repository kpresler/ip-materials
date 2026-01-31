#include <math.h>
#include <stdio.h>


void calculatePowers(int lowerBound, int upperBound) {

    for (int i = lowerBound; i < upperBound; i++) {
        printf("2^%d=%d\n", i, (int)pow(2, i));
    }

}


int main (void) {


    int lower = 0, upper = 10;
    printf("Powers of 2 from 2^%d to 2^%d:\n", lower, upper);
    calculatePowers(lower, upper);


    lower = 5, upper = 17;
    printf("Powers of 2 from 2^%d to 2^%d:\n", lower, upper);
    calculatePowers(lower, upper);



    return 0;
}
