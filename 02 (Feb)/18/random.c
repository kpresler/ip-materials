#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int main (void) {


    // suppose I've got a bag of marbles and I want to grab one at random
    // I've got red, green, and blue marbles, in the following counts

    int marbles[] = {3, 4, 5};

    int count = 12;

    // let's not get the same sequence each time
    srand(time(0));

    while (count) {
        int pick = rand() % count;

        printf("Randomly picking a colour...");

        if (pick < marbles[0]) {
            printf("red!");
            marbles[0]--;
        }
        else if (pick < (marbles[0] + marbles[1])) {
            printf("green!");
            marbles[1]--;
        }
        else {
            printf("blue!");
            marbles[2]--;
        }
        printf("\nCurrent bag of marbles: %d red, %d green, %d blue\n", marbles[0], marbles[1], marbles[2]);
        count--;

    }

}
