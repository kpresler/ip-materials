#include <stdio.h>


int main(void){

    int x;

    printf("Please enter an integer number: ");
    scanf("%d", &x);

    if (x >= 0){
        printf("Your number is positive!\n");
    }
    else {
        printf("Your number is negative\n");
    }


    return 0;
}
