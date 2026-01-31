#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main (int argc, char * argv[]) {

    assert (argc == 2);

    printf("Program run as: %s %s\n", argv[0], argv[1]);

    int maxPow = atoi(argv[1]);


    for (int i = 0; i <= maxPow; i++){
        printf("2^%d=%d\n", i, (int)pow(2, i));
    }


    return 0;
}
