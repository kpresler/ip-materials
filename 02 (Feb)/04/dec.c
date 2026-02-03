#include <stdio.h>
#include <math.h>

void printPowers(int base, int low, int high);


int main (void) {
    printPowers(2, 0, 20);
    return 0;
}



void printPowers(int base, int low, int high) {

    for (int i = low; i < high; i++ ) {
        printf("%d^%d=%d\n", base, i, (int) pow(base, i));
    }


}
