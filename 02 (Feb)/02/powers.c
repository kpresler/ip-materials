#include <math.h>
#include <stdio.h>


int main (void) {


    for (int i = 0; i < 20; i++){
        printf("2^%d=%d\n", i, (int)pow(2, i));
    }


    return 0;
}
