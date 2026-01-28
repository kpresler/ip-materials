#include <stdio.h>


int main(void){

    int x;

    printf("Please enter an integer number: ");
    scanf("%d", &x);

    if (x){
        printf("Your number is nonzero!\n");
    }
    else {
        printf("Your number is zero\n");
    }


    return 0;
}
