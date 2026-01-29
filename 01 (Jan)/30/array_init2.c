#include <stdio.h>


int main(void){

    int grades[12] = {83, 87, 90, 93, 82, 41, 90, 97, 94, 83, 92, 88};

    // actually, don't even need to specify the array sie -- compiler figures it out
    // int grades[] = {83, 87, 90, 93, 82, 41, 90, 97, 94, 83, 92, 88}; // works too!

    for (int i = 0; i < 12; i++){
        printf("grades[%d] = %d\n", i, grades[i]);
    }

    return 0;
}





