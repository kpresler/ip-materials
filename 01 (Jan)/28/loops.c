#include <stdio.h>


int main (void) {


    for (int i = 0; i < 20; i++){
        printf("In for loop, i=%d\n", i);

    }


    double start = 10.0, current = start, target = start * 2;
    int numDays = 0;
    double growthRate = .03;

    while (current < target){
        current = current * (1 + growthRate);
        numDays ++;
    }

    printf("At a growth rate of %f, it took %d days to double our amount\n", growthRate, numDays);


}
