#include <stdio.h>


void array_double(const int numbers[], int size);

int main (void) {


    int numbers[] = {1,2,3,4,5,6};

    printf("in main, our array is located at %p\n", numbers);

    array_double(numbers, sizeof(numbers) / sizeof(numbers[0]));

    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]) ; i++) {
        printf("%d\n", numbers[i]);

    }

    return 0;

}


void array_double(const int numbers[], int size){


    printf("in array_double, our array is located at %p\n", numbers);

    for (int i = 0; i < size ; i++) {
        numbers[i] *= 2;
    }


}
